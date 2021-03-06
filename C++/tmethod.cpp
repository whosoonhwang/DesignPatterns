/*
*/
#include "Foundation.h"
using namespace std;
/*
*/
class Document;
class Application {
public:
  void OpenDocument(const char*);
  virtual bool CanOpenDocument(const char*);
  virtual Document* DoCreateDocument();
  virtual void AboutToOpenDocument(Document* doc);
private:
  List<Document>* _docs;
};
class Document {
public:
  virtual void Open();
  virtual void DoRead();
};
/*
*/
void Application::OpenDocument (const char* name) {
    if (!CanOpenDocument(name)) {
        // cannot handle this document
        return;
    }
/*
*/
    Document* doc = DoCreateDocument();

    if (doc) {
        _docs->Append(*doc);
        AboutToOpenDocument(doc);
        doc->Open();
        doc->DoRead();
    }
}
/*
*/
class ParentClass {
  public:
    void Operation();
    virtual void HookOperation();
};
class DerivedClass : public ParentClass {
  public:
    void Operation();
    virtual void HookOperation();
};
/*
*/
void DerivedClass::Operation () {
    // DerivedClass extended behavior
    ParentClass::Operation();
}
/*
*/
void ParentClass::Operation () {
    // ParentClass behavior
    HookOperation();
}
/*
*/
void ParentClass::HookOperation () { }
/*
*/
void DerivedClass::HookOperation () {
     // derived class extension
}
/*
*/
class View {
public:
    void Display();
    void SetFocus();
    virtual void DoDisplay();
    void ResetFocus();
};

class MyView : public View {
public:
    virtual void DoDisplay();
};
/*
*/
void View::Display () {
    SetFocus();
    DoDisplay();
    ResetFocus();
}
/*
*/
void View::DoDisplay () { }
/*
*/
void MyView::DoDisplay () {
    // render the view's contents
}
/*
*/
