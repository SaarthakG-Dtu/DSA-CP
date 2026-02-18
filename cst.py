import numpy as np
import matplotlib.pyplot as plt
import context
import cst_python_api as cpa

# Project
projectName = "Ring_UnitCell_Grounded"
myCST = cpa.CST_MicrowaveStudio(context.dataFolder, projectName + ".cst")
myCST.Project.setUnits()

# Parameters (mm, GHz)
cell = 2.0
h_sub = 0.1
t_metal = 0.05
r_outer = 0.9
r_inner = 0.7

# Materials
myCST.Build.Material.addNormalMaterial(
    name="Alumina96",
    eps=9.8,
    mu=1.0,
    colour=[0.5, 0.5, 0.25],
    tanD=0.0001
)
# Ground Plane
myCST.Build.Shape.addBrick(
    -0.5*cell, 0.5*cell,
    -0.5*cell, 0.5*cell,
    -t_metal, 0.0,
    name="Ground",
    component="UnitCell",
    material="Copper (annealed)"
)
# Substrate
myCST.Build.Shape.addBrick(
    -0.5*cell, 0.5*cell,
    -0.5*cell, 0.5*cell,
    0.0, h_sub,
    name="Substrate",
    component="UnitCell",
    material="Alumina96"
)
# Ring 
myCST.Build.Shape.addCylinder(
    xMin=0.0, yMin=0.0, zMin=0.1,
    xMax=0.0, yMax=0.0, zMax=0.15,
    extRad=0.9,
    intRad=0.7,
    name="CopperRing",
    component="UnitCell",
    material="Copper (annealed)",
    orientation="z",
    nSegments=0
)
# Solver Setup
myCST.Solver.setFrequencyRange(20.0, 80.0)

myCST.Solver.setBoundaryCondition(
    xMin="unit cell", xMax="unit cell",
    yMin="unit cell", yMax="unit cell",
    zMin="expanded open", zMax="expanded open"
)

myCST.Solver.setFloquetModes(
    nModesX=1,
    nModesY=1
)

myCST.Solver.changeSolverType("HF Frequency Domain")
myCST.Solver.runSimulation()

# Results (Reflection)
freq, S11 = myCST.Results.getSParameters(-1, -1, 1, 1)
plt.plot(freq, 20*np.log10(np.abs(S11)))
plt.xlabel("Frequency (GHz)")
plt.ylabel("|S11| (dB)")
plt.grid()
plt.ylim(-40, 2)
plt.title("Grounded Ring Unit Cell – Reflection")
plt.show()

myCST.saveFile()
