# Concept
This is the repository for the Concept WebApp project. Concept is a note-taking application that allow you to take notes in Markdown format and organize them in a file list structure. The application is written in C++ and use the Qt framework for the GUI. This project is a CMake project and it is available for Windows, Linux and MacOS.

<p align="center">
<img src="/Concept/qml/icons/Conceptlogo.svg" width="200">
</p>

Different external libraries are used in this project:
- QxOrm: is an **Object Relational Mapping** (ORM) and **Object Document Mapper** (ODM) database library for C++ Qt developers. [Homepage](https://www.qxorm.com/qxorm_en/home.html), [Github](https://github.com/QxOrm/QxOrm)
- Maddy: a C++ Markdown to HTML header-only parser library. [Github](https://github.com/progsource/maddy)

# Building the project

To run this project, you need to use git submodules. To clone the repository, use the following command:
```bash
git clone --recurse-submodules https://github.com/ConceptTeam/Concept
```
or
```bash
git clone https://github.com/ConceptTeam/Concept
cd Concept
git submodule init
git submodule update --init --recursive
```

Requirements:
- Qt 6.5.0
- CMake 3.25
- C++14

For Qt Creator, you just need to open the project in Qt Creator and build the project clicking on the build button. For the first build, it may took a while to download and build all the dependencies.

# Members

| Name | Github username | Trello username | Role |
| ---- | --------------- | --------------- | ---- |
| Nguyen Vu | nnguyenu | Nguyen Vu Hoang | Member |
| Bruno Iorio | bruno-iorio | Bruno Iorio | GUI and Database integration |

