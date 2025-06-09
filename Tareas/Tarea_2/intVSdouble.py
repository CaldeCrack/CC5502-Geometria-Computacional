import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

df = pd.read_csv("experiment.csv")
cc_vals = [0.02, 0.04, 0.06, 0.08, 0.10]
df["Tamaño"] = np.log10(df["Tamaño"])

alg_colors = {"gift wrap": "blue", "incremental": "green"}
collinear_styles = {"colineal int": "-", "colineal double": "--"}
CC_styles = {"CC%": "-"}


def plot_points(styles, title):
    for cc in cc_vals:
        df_cc = df[df["CC%"] == cc]

        plt.figure(figsize=(8, 5))

        for algoritmo in ["gift wrap", "incremental"]:
            for punto in styles:
                subset = df_cc[
                    (df_cc["Puntos"] == punto) & (df_cc["Algoritmo"] == algoritmo)
                ]
                if not subset.empty:
                    label = f"{algoritmo} - {punto}"
                    plt.plot(
                        subset["Tamaño"],
                        subset["Tiempo[μs]"],
                        label=label,
                        color=alg_colors[algoritmo],
                        linestyle=styles[punto],
                        marker="o",
                    )

        plt.title(f"{title} (CC% = {cc:.2f})")
        plt.xlabel("Cantidad de puntos (10^x)")
        plt.ylabel("Tiempo [μs]")
        plt.legend()
        plt.grid(True)
        plt.tight_layout()
        plt.savefig(f"img/grafico_{list(styles.keys())[0].split()[0]}_{cc:.2f}%.png")
        plt.show()


plot_points(collinear_styles, "Diferencia de rendimiento con puntos colineales")
plot_points(CC_styles, "Diferencia de rendimiento sin puntos colineales")

df = df[df["Puntos"] == "default"].copy()
plt.figure(figsize=(8, 5))

for algoritmo in ["gift wrap", "incremental"]:
    subset = df[df["Algoritmo"] == algoritmo]
    if not subset.empty:
        plt.plot(
            subset["Tamaño"],
            subset["Tiempo[μs]"],
            label=algoritmo,
            color=alg_colors[algoritmo],
            marker="o",
            linestyle="-",
        )

plt.title("Rendimiento para caso por defecto (puntos aleatorios)")
plt.xlabel("Cantidad de puntos (10^x)")
plt.ylabel("Tiempo [μs]")
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.savefig("img/grafico_default.png")
plt.show()
