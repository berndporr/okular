// fontprogress.h
//
// (C) 2001 Stefan Kebekus
// Distributed under the GPL

#ifndef FONT_GENERATION_H
#define FONT_GENERATION_H

#include <kdialogbase.h>
//#include <qvariant.h>

class QVBoxLayout; 
class QHBoxLayout; 
class QGridLayout; 
class QFrame;
class QLabel;
class KProgress;
class KPushButton;


/**
 *  A dialog to give feedback to the user when kpsewhich is generating fonts.
 *
 * This class implements a dialog which pops up, shows a progress bar
 * and displays the MetaFont output. It contains three slots,
 * outputReceiver, setTotalSteps and hideDialog which can be connected
 * with the appropriate signals emitted by the fontpool class.
 *
 * @author Stefan Kebekus   <kebekus@kde.org>
 *
 *
 **/



class fontProgressDialog : public KDialogBase
{ 
    Q_OBJECT

public:
    fontProgressDialog( QWidget* parent = 0, const QString &name = 0 );
    ~fontProgressDialog();

    QLabel* TextLabel1;
    KProgress* ProgressBar1;
    QLabel* TextLabel2;

public slots:
  /** Used to receive text from the external program. The text
      received here is analyzed and presented to the user. */
  void outputReceiver(QString);

  /** Used to initialize the progress bar. */
  void setTotalSteps(int);

  /** Called when font generation is finished. */
  void hideDialog(void);

  /** Called when the "Help"-Button is pressed. */
  void helpButtonPressed(void);

protected:
    int progress;
};

#endif // FONT_GENERATION_H
