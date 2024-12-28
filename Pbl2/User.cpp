#include "User.h"
#include "ui_User.h"
#include "Payment.h"
#include "Signin.h"
#include "Tenant.h"
#include "Room.h"
#include "ServiceUsage.h"
#include "Booking.h"
#include "Paybill.h"
#include "Extend.h"

User::User(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::User)
{
    ui->setupUi(this);
    ui->roombtn->click();
    Tenant *tenant = Tenant::tenantList.searchID(Account::currentTenantID);
    // ui->Accbtn->setText(QString::fromStdString("  " + Account::currentTenantID));
    ui->Accbtn->setText(QString::fromStdString("  " + tenant->getFirstName()));

    ui->MI_AD->setHidden(true);
    managerooms();
    manageservices();
    managecontracts();
    managepayments();
    AccandNotipopup();
    showprofile();
    showlist();
    showmyroom();
    ui->ID->setText("ID: " + QString::fromStdString(Account::currentTenantID));
    // connect(ui->listWidget, &QListWidget::clicked, this, &User::on_listWidget_clicked);
    connect(ui->LineEditSearchRoom, &QLineEdit::textChanged, this, &User::searchroom);
    connect(ui->LineEditSearchSer, &QLineEdit::textChanged, this, &User::searchSer);
}

User::~User()
{
    delete ui;
}

void User::on_TTCNbtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void User::AccandNotipopup() {
    //Account
    QFrame *AccPopup = new QFrame(this);
    AccPopup->setFrameShape(QFrame::StyledPanel);
    AccPopup->setFixedSize(150, 150);
    AccPopup->setStyleSheet("background-color: white; border: 1px solid gray; border-radius: 5px;");
    AccPopup->hide();

    QVBoxLayout *popupLayout = new QVBoxLayout(AccPopup);

    QVBoxLayout *buttonsLayout = new QVBoxLayout();

    QPushButton *changeAdminCodeBtn = new QPushButton("Profile", AccPopup);
    changeAdminCodeBtn->setStyleSheet("border: none; padding: 10px;text-align: left;");
    buttonsLayout->addWidget(changeAdminCodeBtn);

    QPushButton *changePasswordBtn = new QPushButton("Change Password", AccPopup);
    changePasswordBtn->setStyleSheet("border: none; padding: 10px;text-align: left;");
    buttonsLayout->addWidget(changePasswordBtn);

    QFrame *line = new QFrame(AccPopup);
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Sunken);
    buttonsLayout->addWidget(line);

    QPushButton *logoutBtn = new QPushButton("Sign Out", AccPopup);
    logoutBtn->setStyleSheet("border: none; padding: 10px;text-align: left;");
    buttonsLayout->addWidget(logoutBtn);

    popupLayout->addLayout(buttonsLayout);

    popupLayout->addSpacerItem(new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding));

    AccPopup->move(this->mapToGlobal(QPoint(50, 50)));
    // Notification
    QFrame *notificationPopup = new QFrame(this);
    notificationPopup->setFrameShape(QFrame::StyledPanel);
    notificationPopup->setFixedSize(250, 300);
    notificationPopup->setStyleSheet("background-color: white; border: 1px solid gray; border-radius: 5px;");
    notificationPopup->hide();

    QVBoxLayout *popupLayout1 = new QVBoxLayout(notificationPopup);
    QLabel *titleLabel = new QLabel("Notifications");
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setFixedHeight(40);
    titleLabel->setStyleSheet("font-size: 16px; font-weight: bold; color: purple; background-color: white; border: none;");
    titleLabel->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    popupLayout1->addWidget(titleLabel);

    QWidget *notificationList = new QWidget();
    QVBoxLayout *listLayout = new QVBoxLayout(notificationList);
    listLayout->setContentsMargins(0, 0, 0, 0);
    listLayout->setSpacing(10);

    int check = Payment::checkUnpaidPayments(Account::currentTenantID);
    if ( check!=0 ){
        ui->notifyButton->setIcon(QIcon(":/new/prefix1/Resources/nofitication2.png"));
        QHBoxLayout *notificationLayout = new QHBoxLayout();

        QLabel *messageLabel1 = new QLabel("Payment");
        messageLabel1->setStyleSheet("color: #7A4D9C; margin-left: 10px; border: none;");
        popupLayout1->addWidget(messageLabel1);

        listLayout->addLayout(notificationLayout);
        QLabel *label = new QLabel("Bạn còn " + QString::number(check) + " VNĐ cần thanh toán.");
        label->setStyleSheet("margin-left: 10px; font-size: 14px; border: none;");
        label->setWordWrap(true);
        label->setAlignment(Qt::AlignLeft | Qt::AlignTop);
        popupLayout1->addWidget(label);
    }
    changeAdminCodeBtn->setCursor(Qt::PointingHandCursor);
    changePasswordBtn->setCursor(Qt::PointingHandCursor);
    logoutBtn->setCursor(Qt::PointingHandCursor);
    popupLayout1->addWidget(notificationList);
    popupLayout1->addSpacerItem(new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding));
    connect(ui->notifyButton, &QPushButton::clicked, this, [=]() {
        ui->notifyButton->setIcon(QIcon(":/new/prefix1/Resources/nofitication.png"));
        if (AccPopup->isVisible()) {
            AccPopup->hide();
        }
        if (notificationPopup->isVisible()) {
            notificationPopup->hide();
        } else {
            QPoint buttonGlobalPos = ui->notifyButton->mapToGlobal(QPoint(0, ui->notifyButton->height()));
            QPoint popupParentPos = this->mapFromGlobal(buttonGlobalPos);

            notificationPopup->move(popupParentPos - QPoint(notificationPopup->width() - ui->notifyButton->width(), 0));
            notificationPopup->show();
        }
    });
    connect(ui->Accbtn, &QPushButton::clicked, this, [=]() {
        if (notificationPopup->isVisible()) {
            notificationPopup->hide();
        }
        if (AccPopup->isVisible()) {
            AccPopup->hide();
        } else {
            QPoint buttonGlobalPos = ui->Accbtn->mapToGlobal(QPoint(0, ui->Accbtn->height()));
            QPoint popupParentPos = this->mapFromGlobal(buttonGlobalPos);\
            AccPopup->move(popupParentPos);

            // AccPopup->move(popupParentPos - QPoint(AccPopup->width() - ui->Accbtn->width(), 0));
            AccPopup->show();
        }
    });
    connect(changeAdminCodeBtn, &QPushButton::clicked, [=]() {
        ui->Accbtn->click();
        ui->Accountbtn->click();
        ui->stackedWidget_7->setCurrentIndex(5);
        ui->TTCNbtn->click();
    });
    connect(changePasswordBtn, &QPushButton::clicked, [=]() {
        ui->Accbtn->click();
        ui->Accountbtn->click();
        ui->stackedWidget_7->setCurrentIndex(5);
        ui->Changepassbtn->click();
    });
    connect(logoutBtn, &QPushButton::clicked, [=]() {
        ui->signoutbtn->click();
    });
}

void User::on_editprofilebtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void User::on_signoutbtn_clicked()
{
    Signin *login = new Signin();
    login->show();
    this->close();
    updateAllFile();
}


void User::on_signoutbtn1_clicked()
{
    Signin *login = new Signin();
    login->show();
    this->close();
    updateAllFile();
}


void User::on_Changepassbtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void User::on_Changepass_clicked()
{
    if (ui->newpass->text() == ui->newpass2->text()){
        if (!Account::changePassword(ui->currentpass->text().toStdString(), ui->newpass->text().toStdString())){
            ui->error1->setText("Mật khẩu không đúng");
        } else {
            ui->error1->setText("");
            ui->error2->setText("");
            QMessageBox::information(this, "Success", "Password changed successfully!", QMessageBox::Ok);
            ui->currentpass->clear();
            ui->newpass->clear();
            ui->newpass2->clear();
        }
    } else { ui->error2->setText("Mật khẩu không khớp");}

}

void User::showprofile(){
    Tenant *tenant = Tenant::tenantList.searchID(Account::currentTenantID);
    ui->name->setText(QString::fromStdString(tenant->getFullName()));
    ui->sdt->setText(QString::fromStdString(tenant->getPhone()));
    ui->age->setText(QString::number(tenant->getAge()));
    ui->cccd->setText(QString::fromStdString(tenant->getCCCD()));
    ui->gender->setText(QString::fromStdString(tenant->getGender()? "Nữ" : "Nam"));

    ui->upname->setText(QString::fromStdString(tenant->getFullName()));
    ui->upsdt->setText(QString::fromStdString(tenant->getPhone()));
    ui->upage->setText(QString::number(tenant->getAge()));
    ui->upcccd->setText(QString::fromStdString(tenant->getCCCD()));
    if (tenant->getGender()){
    ui->checkBox_2->setChecked(true);
    } else { ui->checkBox->setChecked(true); }
}

void User::on_updateprofile_clicked()
{
    bool c, gender;
    string firstName, lastName;
    QString name = ui->upname->text();
    string sdt = ui->upsdt->text().toStdString();
    int age = ui->upage->text().toInt(&c);
    string cccd = ui->upcccd->text().toStdString();
     if (ui->checkBox->isChecked()){
        gender = 0;
    } else { gender = 1; }
    int lastSpaceIndex = name.lastIndexOf(' ');
    if (lastSpaceIndex != -1) {
        lastName = name.left(lastSpaceIndex).toStdString();
        firstName = name.mid(lastSpaceIndex + 1).toStdString();
    }
    if (ui->upname->text()=="" || ui->upage->text()=="" || ui->upcccd->text()=="" || ui->upsdt->text()=="") {
        QMessageBox::warning(this, "Warning", "Vui lòng nhập đầy đủ thông tin!");
    } else {
    if (c){
        Tenant::updateTenant(Account::currentTenantID, lastName, firstName, sdt, cccd, age, gender);
        ui->stackedWidget->setCurrentIndex(0);
        QMessageBox::information(this, "Success", "Update successfully!", QMessageBox::Ok);
        showprofile();
    } else {
        QMessageBox::warning(this, "Warning", "Nhập tuổi không hợp lệ!");
    }
    }
}


void User::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void User::managerooms(){
    QAction *searchAction = new QAction(QIcon(":/new/prefix1/Resources/loupe.png"), "Search", this);
    ui->LineEditSearchRoom->addAction(searchAction, QLineEdit::LeadingPosition);
    Room::searchByStatus(0, this);
    // ui->totalroom->setText(QString::number(Room::total));
    ui->table1->horizontalHeader()->setStyleSheet("QHeaderView::section { border: none; }");
    ui->table1->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
    ui->table1->horizontalHeaderItem(ui->table1->columnCount() - 1)->setTextAlignment(Qt::AlignCenter);
    ui->table1->setColumnWidth(0, 150);
    ui->table1->setColumnWidth(1, 150);
    ui->table1->setColumnWidth(2, 200);
    ui->table1->setColumnWidth(3, 150);
    ui->table1->setColumnWidth(4, 150);
    // ui->table1->setColumnWidth(5, 150);
    // ui->table1->setColumnWidth(6, 150);
    ui->table1->verticalHeader()->hide();

    //sx
    QRect headerRect = ui->table1->visualRect(ui->table1->model()->index(0, 0));
    QPushButton* sortButton = new QPushButton(ui->table1);
    sortButton->setText("");
    sortButton->setIcon(QIcon(":/new/prefix1/Resources/sxtang.png"));
    sortButton->setFixedSize(16, 16);
    sortButton->setToolTip("Sort by Room ID");
    sortButton->move(headerRect.right() - 90, headerRect.top() + 3);
    sortButton->setCheckable(true);
    connect(sortButton, &QPushButton::toggled, this, [this, sortButton](bool checked) {
        if (checked) {
            sortButton->setIcon(QIcon(":/new/prefix1/Resources/sxgiam.png"));
            Room::Descending();
            ui->table1->clearContents();
            ui->table1->setRowCount(0);
            Room::searchByStatus(0, this);
            if (ui->CBSR->currentIndex() == 1 && !ui->LineEditSearchRoom->text().isEmpty()){
                sortButton->setIcon(QIcon(":/new/prefix1/Resources/sxgiam.png"));
                Room::Descending();
                ui->table1->clearContents();
                ui->table1->setRowCount(0);
                Room::searchByID(ui->LineEditSearchRoom->text().toStdString(), this);
            }
            if (ui->CBSR->currentIndex() == 2 && !ui->LineEditSearchRoom->text().isEmpty()){
                sortButton->setIcon(QIcon(":/new/prefix1/Resources/sxgiam.png"));
                Room::Descending();
                ui->table1->clearContents();
                ui->table1->setRowCount(0);
                Room::searchByRoomType(ui->LineEditSearchRoom->text().toStdString(), this);
            }
        } else {
            sortButton->setIcon(QIcon(":/new/prefix1/Resources/sxtang.png"));
            Room::Ascending();
            ui->table1->clearContents();
            ui->table1->setRowCount(0);
            Room::searchByStatus(0, this);
            if (ui->CBSR->currentIndex() == 1 && !ui->LineEditSearchRoom->text().isEmpty()){
                sortButton->setIcon(QIcon(":/new/prefix1/Resources/sxtang.png"));
                Room::Ascending();
                ui->table1->clearContents();
                ui->table1->setRowCount(0);
                Room::searchByID(ui->LineEditSearchRoom->text().toStdString(), this);
            }
            if (ui->CBSR->currentIndex() == 2 && !ui->LineEditSearchRoom->text().isEmpty()){
                sortButton->setIcon(QIcon(":/new/prefix1/Resources/sxtang.png"));
                Room::Ascending();
                ui->table1->clearContents();
                ui->table1->setRowCount(0);
                Room::searchByRoomType(ui->LineEditSearchRoom->text().toStdString(), this);
            }
        }
    });
}

void User::showlist(){
    LinkedList<Room>::Node* current = Room::roomList.begin();
    while (current != nullptr) {
        if (current->data.getTenantID() == Account::currentTenantID) {
            QListWidgetItem *newItem = new QListWidgetItem;
            newItem->setText(QString::fromStdString(current->data.getID()));
            QFont f;

            f.setPointSize(11);
            newItem->setFont(f);
            ui->listWidget->addItem(newItem);
            ui->listWidget_2->addItem(newItem);
        }
        current = current->next;
    }
}
void User::showmyroom(){
    LinkedList<Room>::Node* current = Room::roomList.begin();
    while (current != nullptr) {
        if (current->data.getTenantID() == Account::currentTenantID) {
            QListWidgetItem *newItem = new QListWidgetItem;
            newItem->setText(QString::fromStdString(current->data.getID()));
            QFont f;

            f.setPointSize(11);
            newItem->setFont(f);
            ui->listWidget_2->addItem(newItem);
        }
        current = current->next;
    }
}

void User::manageservices(){
    QAction *searchAction = new QAction(QIcon(":/new/prefix1/Resources/loupe.png"), "Search", this);
    ui->LineEditSearchSer->addAction(searchAction, QLineEdit::LeadingPosition);
    ui->SerTable->horizontalHeader()->setStyleSheet("QHeaderView::section { border: none; }");
    ui->SerTable->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
    ui->SerTable->horizontalHeaderItem(ui->SerTable->columnCount() - 1)->setTextAlignment(Qt::AlignCenter);
    // ui->SerTable->setColumnWidth(0, 200);
    // ui->SerTable->setColumnWidth(1, 200);
    ui->SerTable->setColumnWidth(2, 200);
    // ui->SerTable->setColumnWidth(3, 200);
    // ui->SerTable->setColumnWidth(4, 200);
    ui->SerTable->verticalHeader()->hide();
    ui->SerTable->setShowGrid(false);
}

void User::managecontracts(){
    Contract::searchByTenantID(Account::currentTenantID, 0, this);
    ui->ContractTable->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
    ui->ContractTable->horizontalHeader()->setStyleSheet("QHeaderView::section { border: none; }");
    ui->ContractTable->horizontalHeaderItem(ui->ContractTable->columnCount() - 1)->setTextAlignment(Qt::AlignCenter);
    ui->ContractTable->setColumnWidth(5, 50);
    ui->ContractTable->setColumnWidth(11, 50);
    ui->ContractTable->verticalHeader()->hide();
    ui->ContractTable->setShowGrid(false);
}

void User::managepayments(){
    Payment::searchByTenantID(Account::currentTenantID, this);
    ui->PaymentTable->setColumnWidth(6, 70);
    ui->PaymentTable->setColumnWidth(7, 70);
    ui->PaymentTable->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
    ui->PaymentTable->horizontalHeader()->setStyleSheet("QHeaderView::section { border: none; }");
    ui->PaymentTable->horizontalHeaderItem(ui->PaymentTable->columnCount() - 1)->setTextAlignment(Qt::AlignCenter);
    ui->PaymentTable->verticalHeader()->hide();
    ui->PaymentTable->setShowGrid(false);
}

void User::displayRooms(const Room& room) {
    string tenantName = "N/A";
    Tenant* tenant = Tenant::tenantList.searchID(room.getTenantID());
    if (tenant != nullptr) {
        tenantName = tenant->getFullName();
    }
    int row = ui->table1->rowCount();
    ui->table1->insertRow(row);

    ui->table1->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(room.getID())));
    ui->table1->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(room.getRoomTypeID())));
    ui->table1->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(room.getRoomType()->getName())));
    ui->table1->setItem(row, 3, new QTableWidgetItem(QString::fromStdString(room.getRoomType()->getDescription())));
    ui->table1->setItem(row, 4, new QTableWidgetItem(QString::number(room.getRoomType()->getPrice(), 'f', 2)));

    QWidget* buttonWidget = new QWidget();
    QPushButton* editButton = new QPushButton();
    editButton->setIcon(QIcon(":/new/prefix1/Resources/booking2.png"));
    editButton->setToolTip("Book");
    connect(editButton, &QPushButton::clicked, this, [this, row]() {
        onEditButtonClicked(row);
    });

    QHBoxLayout* layout = new QHBoxLayout(buttonWidget);
    layout->addWidget(editButton);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);
    editButton->setFixedSize(20, 20);

    buttonWidget->setLayout(layout);

    ui->table1->setCellWidget(row, 5, buttonWidget);
}

void User::displayServices(const Service& s) {
    int row = ui->SerTable->rowCount();
    ui->SerTable->insertRow(row);

    ui->SerTable->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(s.getID())));
    ui->SerTable->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(s.getName())));
    ui->SerTable->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(s.getdes())));
    ui->SerTable->setItem(row, 3, new QTableWidgetItem(QString::number(s.getUnitPrice())));
    ui->SerTable->setItem(row, 4, new QTableWidgetItem(s.getis_mandatory()? "Cố định" : "Tự do"));
        LinkedList<ServiceUsage>::Node* current = ServiceUsage::usageList.begin();
        while (current) {
            if (ui->listWidget->currentItem()->text() == current->data.getRoomID() && ui->SerTable->item(row, 0)->text() == current->data.getServiceID()){
                ui->SerTable->setItem(row, 5, new QTableWidgetItem(QString::fromStdString(current->data.getStatus()? "Active" : "Inactive")));
                break;
            }
            ui->SerTable->setItem(row, 5, new QTableWidgetItem(QString::fromStdString("Inactive")));
            current = current->next;
        }
        if (ui->SerTable->item(row, 5)->text() == "Inactive"){
            QWidget* buttonWidget = new QWidget();
            QPushButton* edit_Ser_btn = new QPushButton();
            // edit_Ser_btn->setIcon(QIcon(":/new/prefix1/Resources/edit.png"));
            edit_Ser_btn->setText("Register");
            connect(edit_Ser_btn, &QPushButton::clicked, this, [this, row]() {
                onedit_Ser_btnClicked(row);
            });
            QHBoxLayout* layout = new QHBoxLayout(buttonWidget);
            layout->addWidget(edit_Ser_btn);
            layout->setContentsMargins(0, 0, 0, 0);
            layout->setSpacing(0);
            edit_Ser_btn->setFixedSize(70, 23);
            buttonWidget->setLayout(layout);
            ui->SerTable->setCellWidget(row, 6, buttonWidget);
        }

        if (ui->SerTable->item(row, 5)->text() == "Active" && ui->SerTable->item(row, 4)->text() == "Tự do"){
            QWidget* buttonWidget = new QWidget();
            QPushButton* delete_Ser_btn = new QPushButton();
            // delete_Ser_btn->setIcon(QIcon(":/new/prefix1/Resources/delete.png"));
            delete_Ser_btn->setText("Unregister");
            connect(delete_Ser_btn, &QPushButton::clicked, this, [this, row]() {
                ondelete_Ser_btnClicked(row);
            });

            QHBoxLayout* layout = new QHBoxLayout(buttonWidget);
            layout->addWidget(delete_Ser_btn);
            layout->setContentsMargins(0, 0, 0, 0);
            layout->setSpacing(0);
            delete_Ser_btn->setFixedSize(70, 23);

            buttonWidget->setLayout(layout);

            ui->SerTable->setCellWidget(row, 6, buttonWidget);
        }
}

void User::displayContracts(const Contract& c){
    int row = ui->ContractTable->rowCount();
    ui->ContractTable->insertRow(row);
    Tenant* t = Tenant::tenantList.searchID(c.getTenantID());
    Room* r = Room::roomList.searchID(c.getRoomID());
    ui->ContractTable->setRowHeight(row, 50);
    ui->ContractTable->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(c.getID())));
    ui->ContractTable->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(c.getRoomID())));
    ui->ContractTable->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(r->getRoomType()->getName())));
    ui->ContractTable->setItem(row, 3, new QTableWidgetItem(QString::fromStdString(c.getTenantID())));
    ui->ContractTable->setItem(row, 4, new QTableWidgetItem(QString::fromStdString(t->getFullName())));
    ui->ContractTable->setItem(row, 5, new QTableWidgetItem(QString::number(t->getAge())));
    ui->ContractTable->setItem(row, 6, new QTableWidgetItem(QString::fromStdString(t->getCCCD())));
    ui->ContractTable->setItem(row, 7, new QTableWidgetItem(QString::fromStdString(t->getPhone())));
    ui->ContractTable->setItem(row, 8, new QTableWidgetItem(QString::fromStdString(c.getStartDate().toString())));
    ui->ContractTable->setItem(row, 9, new QTableWidgetItem(QString::fromStdString(c.getEndDate().toString())));
    ui->ContractTable->setItem(row, 10, new QTableWidgetItem((QString("%1 VND/1 month").arg(QString::number(c.getrentprice(), 'f', 2)))));
    ui->ContractTable->setItem(row, 11, new QTableWidgetItem(QString::fromStdString(c.getStatus() == 1 ? "Active" : "Expired")));
    if (c.getStatus() == 1){
        QWidget* buttonWidget = new QWidget();

        QPushButton* terminate_btn = new QPushButton();
        terminate_btn->setIcon(QIcon(":/new/prefix1/Resources/rejectcontract.png"));
        terminate_btn->setToolTip("Hủy thuê");
        connect(terminate_btn, &QPushButton::clicked, this, [this, row]() {
            onterminate_btnClicked(row);
        });

        QPushButton* extendButton = new QPushButton();
        extendButton->setIcon(QIcon(":/new/prefix1/Resources/extend.png"));
        extendButton->setToolTip("Gia hạn");
        connect(extendButton, &QPushButton::clicked, this, [this, row]() {
            onExtendButtonClicked(row);
        });

        QHBoxLayout* layout = new QHBoxLayout(buttonWidget);
        layout->addWidget(extendButton);
        layout->addWidget(terminate_btn);
        layout->setContentsMargins(0, 0, 0, 0);
        layout->setSpacing(0);
        terminate_btn->setIconSize(QSize(20, 20));
        extendButton->setIconSize(QSize(30, 30));

        buttonWidget->setLayout(layout);

        ui->ContractTable->setCellWidget(row, 12, buttonWidget);
    }
}

void User::displayPayments(const Payment& p){
    int row = ui->PaymentTable->rowCount();
    ui->PaymentTable->insertRow(row);
    ui->PaymentTable->setRowHeight(row, 40);

    ui->PaymentTable->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(p.getID())));
    ui->PaymentTable->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(p.getRoomID())));
    ui->PaymentTable->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(p.getTenantID())));
    ui->PaymentTable->setItem(row, 3, new QTableWidgetItem(QString::number(p.getRentAmount(), 'f', 2)));
    ui->PaymentTable->setItem(row, 4, new QTableWidgetItem(QString::number(p.getServiceAmount(), 'f', 2)));
    ui->PaymentTable->setItem(row, 5, new QTableWidgetItem(QString::number(p.getTotalAmount(), 'f', 2)));
    ui->PaymentTable->setItem(row, 6, new QTableWidgetItem(QString::number(p.getBillMonth())));
    ui->PaymentTable->setItem(row, 7, new QTableWidgetItem(QString::number(p.getBillYear())));
    ui->PaymentTable->setItem(row, 8, new QTableWidgetItem(QString::fromStdString(p.getpayDate().toString())));
    QTableWidgetItem *status = new QTableWidgetItem(QString::fromStdString(p.getStatus() ? "Paid" : "Pending"));
    QFont font = status->font();
    font.setBold(true);
    status->setFont(font);
    if (p.getStatus()) {
        status->setForeground(QColor(0, 255, 0));
    } else {
        status->setForeground(QColor(255, 165, 0));
    }
    ui->PaymentTable->setItem(row, 9, status);
    ui->PaymentTable->setItem(row, 10, new QTableWidgetItem(QString::number(p.getdepositAmount(), 'f', 2)));
    ui->PaymentTable->setItem(row, 11, new QTableWidgetItem(QString::number(p.getRemainingAmount(), 'f', 2)));
    if (p.getRemainingAmount() != 0){
        QWidget* buttonWidget = new QWidget();

        QPushButton* pay_btn = new QPushButton();
        // terminate_btn->setIcon(QIcon(":/new/prefix1/Resources/rejectcontract.png"));
        pay_btn->setText("Pay");
        connect(pay_btn, &QPushButton::clicked, this, [this, row]() {
            onpay_btnbtnClicked(row);
        });

        QHBoxLayout* layout = new QHBoxLayout(buttonWidget);
        layout->addWidget(pay_btn);
        layout->setContentsMargins(0, 0, 0, 0);
        layout->setSpacing(0);
        pay_btn->setFixedSize(70, 23);

        buttonWidget->setLayout(layout);

        ui->PaymentTable->setCellWidget(row, 12, buttonWidget);
    }
}

void User::on_listWidget_clicked(){
    ui->SerTable->clearContents();
    ui->SerTable->setRowCount(0);
    Service::showAllServices(this);
}

void User::onEditButtonClicked(int row){
    Booking b(ui->table1->item(row, 0)->text().toStdString(), this);
    b.exec();
    ui->table1->clearContents();
    ui->table1->setRowCount(0);
    Room::searchByStatus(0, this);
}

void User::on_roombtn_clicked()
{
    ui->stackedWidget_7->setCurrentIndex(1);
}


void User::on_pushButton_3_clicked()
{
    ui->stackedWidget_7->setCurrentIndex(1);
}


void User::on_Serbtn1_clicked()
{
    ui->stackedWidget_7->setCurrentIndex(2);
}


void User::on_Serbtn_clicked()
{
    ui->stackedWidget_7->setCurrentIndex(2);
}


void User::on_Paymentbtn_clicked()
{
    ui->stackedWidget_7->setCurrentIndex(3);
}


void User::on_Paymentbtn1_clicked()
{
    ui->stackedWidget_7->setCurrentIndex(3);
}


void User::on_Contractbtn_clicked()
{
    ui->stackedWidget_7->setCurrentIndex(4);
}


void User::on_Contractbtn1_clicked()
{
    ui->stackedWidget_7->setCurrentIndex(4);
}

void User::onedit_Ser_btnClicked(int i){
    ServiceUsage::addServiceUsage(ui->listWidget->currentItem()->text().toStdString(), ui->SerTable->item(i, 0)->text().toStdString());
    QMessageBox::information(this, "Đăng ký", "Đăng ký thành công!");
    on_listWidget_clicked();
}

void User::ondelete_Ser_btnClicked(int i){
    ServiceUsage::stopService(ui->listWidget->currentItem()->text().toStdString(), ui->SerTable->item(i, 0)->text().toStdString());
    QMessageBox::information(this, "Hủy", "Hủy dịch vụ thành công!");
    on_listWidget_clicked();
}

void User::on_listWidget_2_clicked(){
    LinkedList<Room>::Node* current = Room::roomList.begin();
    while (current){
        if (ui->listWidget_2->currentItem()->text() == current->data.getID()){
            ui->roomID->setText(QString::fromStdString(current->data.getID()));
            ui->RTID->setText(QString::fromStdString(current->data.getRoomTypeID()));
            ui->RT->setText(QString::fromStdString(current->data.getRoomType()->getName()));
            ui->Price->setText(QString::number(current->data.getPrice()));
            ui->Desc->setText(QString::fromStdString(current->data.getRoomType()->getDescription()));
            ui->stackedWidget_2->setCurrentIndex(1);
            return;
        }
        current = current->next;
    }
}

void User::on_backbtn_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
}

void User::onterminate_btnClicked(int row){
    if (Payment::checkUnpaidPaymentForRoom(Account::currentTenantID, ui->ContractTable->item(row, 1)->text().toStdString())) {
        QMessageBox::information(this, "Thông báo", "Bạn cần thanh toán trước khi hủy hợp đồng");
        return;
    }
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Xác nhận", "Bạn có chắc chắn muốn hủy hợp đồng này không?", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        Contract::deleteContract(ui->ContractTable->item(row, 1)->text().toStdString());
        ui->ContractTable->clearContents();
        ui->ContractTable->setRowCount(0);
        Contract::searchByTenantID(Account::currentTenantID, 0, this);
        ui->table1->clearContents();
        ui->table1->setRowCount(0);
        Room::searchByStatus(0, this);
        ui->listWidget->clear();
        ui->listWidget_2->clear();
        showlist();
        showmyroom();
    }
}

void User::onpay_btnbtnClicked(int row){
    Paybill pay(ui->PaymentTable->item(row, 0)->text().toStdString(), this);
    pay.exec();
    ui->PaymentTable->clearContents();
    ui->PaymentTable->setRowCount(0);
    Payment::searchByTenantID(Account::currentTenantID, this);
}

void User::updateAllFile() {
    RoomType::updateFile("RoomType.txt");
    Room::updateFile("Room.txt");
    Tenant::updateFile("Tenant.txt");
    Service::updateFile("Service.txt");
    ServiceUsage::updateFile("ServiceUsage.txt");
    Reservation::updateFile("Reservation.txt");
    Contract::updateFile("Contract.txt");
    Payment::updateFile("Payment.txt");
    Account::updateFile("Account.txt");
}

void User::on_Accbtn_2_clicked()
{
    ui->Accbtn->click();
}

void User::searchroom()
{
    string search = ui->LineEditSearchRoom->text().toStdString();
    string check = ui->CBSR->currentText().toStdString();
    if (search.empty()) {
        ui->table1->clearContents();
        ui->table1->setRowCount(0);
        Room::searchByStatus(0, this);
    }
    if (check == "Room ID"){
        ui->table1->clearContents();
        ui->table1->setRowCount(0);
        Room::searchByID(search, this);
    }
    if (ui->CBSR->currentText() == "Room Type"){
        ui->table1->clearContents();
        ui->table1->setRowCount(0);
        Room::searchByRoomType(search, this);
    }
}

void User::searchSer()
{
    string search = ui->LineEditSearchSer->text().toStdString();
    string check = ui->CBSS->currentText().toStdString();
    if (search.empty()) {
        ui->SerTable->clearContents();
        ui->SerTable->setRowCount(0);
        Service::showAllServices(this);
    }
    if (check == "Service ID"){
        ui->SerTable->clearContents();
        ui->SerTable->setRowCount(0);
        Service::searchByID(search, this);
    }
    if (check == "Service Name"){
        ui->SerTable->clearContents();
        ui->SerTable->setRowCount(0);
        Service::searchByName(search, this);
    }
}

void User::on_searchPayment_clicked()
{
    int month = ui->CBSP->currentText().toInt();
    int year = ui->LineEditSearchPayment->text().toInt();
    ui->PaymentTable->clearContents();
    ui->PaymentTable->setRowCount(0);
    Payment::searchByMonth(month, year, this);
}

void User::onExtendButtonClicked(int row){
    string id = ui->ContractTable->item(row, 1)->text().toStdString();
    Extend e(id, this);
    e.exec();
    ui->ContractTable->clearContents();
    ui->ContractTable->setRowCount(0);
    Contract::searchByTenantID(Account::currentTenantID, 0, this);
}

void User::on_RefPaymentbtn_clicked()
{
    ui->LineEditSearchPayment->clear();
    ui->CBSP->setCurrentIndex(0);
    ui->PaymentTable->clearContents();
    ui->PaymentTable->setRowCount(0);
    Payment::searchByTenantID(Account::currentTenantID, this);
}

void User::on_Refbtn_clicked()
{
    ui->table1->clearContents();
    ui->table1->setRowCount(0);
    Room::searchByStatus(0, this);
    ui->LineEditSearchRoom->clear();
    ui->CBSR->setCurrentIndex(0);
}
