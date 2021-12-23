# dijkstra-s-shortest-path
This program finds the shortest path between two nodes, when given a list of edges between the nodes

# Conda environment
## Downloading Conda
* Download miniconda here: https://docs.conda.io/en/latest/miniconda.html DO NOT ADD CONDA TO WINDOWS PATH
* Once complete, open a miniconda terminal by searching for "miniconda" in the windows search bar

## Creating environment from env
* In the miniconda terminal, navigate to the repo and execute `conda env create -f environment.yml`

## Activating the environment
* In the miniconda terminal, execute `conda activate dijkstra`

# Building
With the conda environment active, execute: 
* `meson setup build`
* `cd build`
* `meson compile`
The executable will be placed in build/src/dijkstra.exe
