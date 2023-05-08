# Librerías
# ======================================================================================
import networkx as nx
import numpy as np
import pandas as pd
import warnings
import scipy as sp
import matplotlib.pyplot as plt
from matplotlib.widgets import Button
import tkinter as tk

warnings.filterwarnings("ignore")

G = nx.Graph()
print(G)

G.is_directed()

Grafos = pd.read_csv(
    "C:\\Users\\USER\\Documents\\UdeG\\Seminario Estructuras de Datos 2\\Python Act 12\\Lineas de CDMX.txt",
    header=None,
    sep=",",
    names=["Nodo", "Relacion"],
)

relaciones = np.zeros((len(Grafos), 2), dtype=int)

for i, row in Grafos.iterrows():
    relaciones[i][0] = int(row["Nodo"])
    relaciones[i][1] = int(row["Relacion"])

print("Arreglo Bidimencional")

for i in relaciones:
    print(i)

print(Grafos)
# Añadir multiples nodos
# ======================================================================================
for i in range(len(relaciones)):
    nodo_1 = relaciones[i][0]
    nodo_2 = relaciones[i][1]
    G.add_node(nodo_1)
    G.add_node(nodo_2)
    G.add_edge(nodo_1, nodo_2)

fig, ax = plt.subplots(figsize=(1, 1))
nx.draw(G, with_labels=True, ax=ax)
ax.set_xlim([1.2*x for x in ax.get_xlim()])
ax.set_ylim([1.2*y for y in ax.get_ylim()])

print(G)

adjM = nx.adjacency_matrix(G)
IncM = nx.incidence_matrix(G)

with open("C:\\Users\\USER\\Documents\\UdeG\\Seminario Estructuras de Datos 2\\Python Act 12\\Lineas de CDMX Matriz de Adyacencia.txt"
          ,"w") as archivo:
  for i in range(adjM.shape[0]):
    for j in range(adjM.shape[1]):
        archivo.write(f"{int(adjM[i,j])} ")
    archivo.write("\n")


with open("C:\\Users\\USER\\Documents\\UdeG\\Seminario Estructuras de Datos 2\\Python Act 12\\Lineas de CDMX Matriz de Incidencia.txt"
          ,"w") as archivo:
    for i in range(IncM.shape[0]):
        for j in range(IncM.shape[1]):
            archivo.write(f"{int(IncM[i,j])} ")
        archivo.write("\n")



def eliminar_grafo(event):
    G.clear()
    ax.clear()
    plt.draw()

# Crear botón y conectar con función para eliminar grafo
ax_eliminar = plt.axes([0.85, 0.80, 0.1, 0.05])
btn_eliminar = Button(ax_eliminar, 'Eliminar Grafo')
btn_eliminar.on_clicked(eliminar_grafo)

# Definir función para eliminar nodo
def remove_node(event):
    popup = tk.Tk()
    popup.title("Eliminar Nodo")
    label = tk.Label(popup, text="Ingrese el número del nodo:")
    label.pack()
    entry = tk.Entry(popup)
    entry.pack()
    
    def delete_node():
        node = int(entry.get())
        # Código para eliminar el nodo aquí
        if G.has_node(node):
            G.remove_node(node)
            print("Nodo Eliminado")
            ax.clear()
            nx.draw(G, with_labels=True, ax=ax)
            ax.set_xlim([1.2*x for x in ax.get_xlim()])
            ax.set_ylim([1.2*y for y in ax.get_ylim()])
            plt.draw()
        else:
            print("El nodo no existe en el grafo")
        
        # Redibujar el gráfico con los nodos y aristas actuales
        
    button = tk.Button(popup, text="Eliminar", command=delete_node)
    button.pack()
    popup.mainloop()

# Agregar botón con entrada de texto
plt.subplots_adjust(bottom=0.2) # Ajustar la posición del botón
remove_button = plt.axes([0.7, 0.05, 0.2, 0.075]) # Posición del botón en el gráfico
button = plt.Button(remove_button, 'Eliminar Nodo', color='purple') # Crear el botón
button.on_clicked(remove_node) # Asignar función al hacer clic en el botón

# Definir función para eliminar nodo
def remove_edge(event):
    popup = tk.Tk()
    popup.title("Eliminar Arista")
    label = tk.Label(popup, text="Ingrese el número del nodo origen:")
    label.pack()
    entry = tk.Entry(popup)
    entry.pack()
    label2 = tk.Label(popup, text="Ingrese el número del nodo destino:")
    label2.pack()
    entryE = tk.Entry(popup)
    
    entryE.pack()
    
    def delete_edge():
        node = int(entry.get())
        dest = int(entryE.get())
        # Código para eliminar el nodo aquí
        if G.has_node(node):
            G.remove_edge(node,dest)
            print("Arista Eliminada")
            ax.clear()
            nx.draw(G, with_labels=True, ax=ax)
            ax.set_xlim([1.2*x for x in ax.get_xlim()])
            ax.set_ylim([1.2*y for y in ax.get_ylim()])
            plt.draw()
        else:
            print("El nodo no existe en el grafo")
        
        # Redibujar el gráfico con los nodos y aristas actuales
        
    button_Edge = tk.Button(popup, text="Eliminar", command=delete_edge)
    button_Edge.pack()
    popup.mainloop()

# Agregar botón con entrada de texto
plt.subplots_adjust(bottom=0.2) # Ajustar la posición del botón
remove_button_Edge = plt.axes([0.10, 0.05, 0.2, 0.075]) # Posición del botón en el gráfico
button_Edge = plt.Button(remove_button_Edge, 'Eliminar Arista', color='blue') # Crear el botón
button_Edge.on_clicked(remove_edge) # Asignar función al hacer clic en el botón

# Definir función para Agregar Arista
def add_Edge(event):
    popup = tk.Tk()
    popup.title("Agregar Arista")
    label = tk.Label(popup, text="Ingrese el número del nodo origen:")
    label.pack()
    entry = tk.Entry(popup)
    entry.pack()
    label2 = tk.Label(popup, text="Ingrese el número del nodo destino:")
    label2.pack()
    entryE = tk.Entry(popup)
    entryE.pack()
    
    def add_edge():
        node = int(entry.get())
        dest = int(entryE.get())
        # Código para agregar el arista aquí
        if G.has_node(node):
            G.add_edge(node,dest)
            print("Arista Agregada")
            ax.clear()
            nx.draw(G, with_labels=True, ax=ax)
            ax.set_xlim([1.2*x for x in ax.get_xlim()])
            ax.set_ylim([1.2*y for y in ax.get_ylim()])
            plt.draw()
        else:
            print("No se Agrego")
        
        # Redibujar el gráfico con los nodos y aristas actuales
        
    button_Edge_add = tk.Button(popup, text="Agregar Arista", command=add_edge)
    button_Edge_add.pack()
    popup.mainloop()

# Agregar botón con entrada de texto
plt.subplots_adjust(bottom=0.2) # Ajustar la posición del botón
button_Edge_add_b = plt.axes([0.40, 0.05, 0.2, 0.075]) # Posición del botón en el gráfico
button_Edge_add = plt.Button(button_Edge_add_b, 'Agregar Arista', color='yellow') # Crear el botón
button_Edge_add.on_clicked(add_Edge) # Asignar función al hacer clic en el botón

# Definir función para Agregar Arista
def add_Nodes(event):
    popup = tk.Tk()
    popup.title("Agregar Nodo")
    label = tk.Label(popup, text="Ingrese el número del nodo origen:")
    label.pack()
    entry = tk.Entry(popup)
    entry.pack()
    
    def add_Node():
        node = int(entry.get())
        # Código para agregar el arista aquí
        if G.has_node(node):
            G.add_node(node)
            print("Nodo Agregado")
            ax.clear()
            nx.draw(G, with_labels=True, ax=ax)
            ax.set_xlim([1.2*x for x in ax.get_xlim()])
            ax.set_ylim([1.2*y for y in ax.get_ylim()])
            plt.draw()
        else:
            print("No se Agrego")
        
        # Redibujar el gráfico con los nodos y aristas actuales
        
    button_Node_add = tk.Button(popup, text="Agregar Nodo", command=add_Node)
    button_Node_add.pack()
    popup.mainloop()

# Agregar botón con entrada de texto
plt.subplots_adjust(bottom=0.2) # Ajustar la posición del botón
button_node_add_b = plt.axes([0.85, 0.50, 0.2, 0.010]) # Posición del botón en el gráfico
button_Node_add = plt.Button(button_node_add_b, 'Agregar Nodo', color='Gray') # Crear el botón
button_Node_add.on_clicked(add_Nodes) # Asignar función al hacer clic en el botón


plt.show()
