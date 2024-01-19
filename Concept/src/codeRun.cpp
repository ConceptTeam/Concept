#include "codeRun.h"
#include <QVBoxLayout>

CodeRun::CodeRun(QQuickItem *parent) : QQuickItem(parent)
{
    initializePython();
}

CodeRun::~CodeRun()
{
    finalizePython();
}

void CodeRun::handleRunAction(const QString &content)
{
    PyGILState_STATE gstate;
    gstate = PyGILState_Ensure();

    PyObject *pModule = PyImport_ImportModule("__main__");
    PyObject *pDict = PyModule_GetDict(pModule);
    PyObject *pResult = PyRun_String(content.toStdString().c_str(), Py_file_input, pDict, pDict);

    QString output;
    if (pResult == NULL)
    {
        PyErr_Print();
        output = "Error executing the code.";
    }
    else
    {
        PyObject *pResultStr = PyObject_Repr(pResult);
        const char *resultCStr = PyUnicode_AsUTF8(pResultStr);
        output = QString(resultCStr);
        Py_DECREF(pResultStr);
        Py_DECREF(pResult);
    }

    Py_DECREF(pDict);
    Py_DECREF(pModule);

    PyGILState_Release(gstate);

    CodeDialog *dialog = new CodeDialog(nullptr, output);
    dialog->show();
}

void CodeRun::initializePython()
{
    Py_Initialize();
    pythonThreadState = PyEval_SaveThread();
}

void CodeRun::finalizePython()
{
    PyEval_RestoreThread(pythonThreadState);
    Py_Finalize();
}

CodeDialog::CodeDialog(QWidget *parent, const QString &output) : QDialog(parent)
{
    setWindowTitle("Code Output");
    titleLabel = new QLabel("Output:", this);
    outputText = new QTextEdit(this);
    closeButton = new QPushButton("Close Window", this);

    outputText->setPlainText(output);
    outputText->setReadOnly(true);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(titleLabel);
    layout->addWidget(outputText);
    layout->addWidget(closeButton);

    connect(closeButton, &QPushButton::clicked, this, &QDialog::close);
}

CodeDialog::~CodeDialog()
{
    delete closeButton;
    delete outputText;
    delete titleLabel;
    delete codeDialog;
}
