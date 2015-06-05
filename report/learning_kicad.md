#Learning KiCAD

KiCAD is an open source EDA tool, useful to capture electronic design, do some preliminary electrical checks, create PCB
design based on these inputs.

## Installation

Click [here](http://www.kicad-pcb.org/display/KICAD/Installing+KiCad) for installation details.

## Creating Schematic

In this module (Eeschema), modules are placed and interconnected to show electrical connections. Modules exist as library
which can be edited to update existing components or create new components. New libraries may be placed in the 
defined search paths, or new search path may be added to facilitate picking up those libraries.

Component has got pins which are divided into two categories - Passive / Dummies and Power Components. Latter category helps for eletric
connection validations. Also, there are two types of pins in each category - input or output.

While placing wires, one can place junctions to facilitate more than one wires terminating at a point. Every component 
is uniquely identified by its label. Every component has got value, which can be altered as per design, however this does
not add any value to the electrical checks.

While creating schematic, one need to annotate to get these component labels automatically placed (it can be done manually
as well) and can generate netlist.

Netlist is a list of components and their interconnection in textual format for data transfer to other tools

It also helps to generate Bill Of Materials (BoM) i.e. Label, Item Description, Quantity.

## Assigning Components to Layouts/Packages/Modules
In this module (CvPCB)


## Placing Components
In this module (PCBnew)
 At this point, one has to install the libraries. Click this [link](https://github.com/KiCad/kicad-library) for more details.
## Routing
