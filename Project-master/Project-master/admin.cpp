#include "admin.h"
#include "ui_admin.h"
#include "Login.h"
#include <QFile>
#include "Room.h"
#include "Tenant.h"
#include "Service.h"
#include "ServiceUsage.h"
#include "Reservation.h"
#include "Contract.h"
#include "Payment.h"
#include "Account.h"
#include "PaymentStatistics.h"
#include "Addroom.h"
#include "AddService.h"
#include "Editroom.h"
#include "Edittenant.h"
#include "Editservice.h"
#include "Editroomtype.h"
#include "Createpayment.h"
#include <QMessageBox>
#include <QPropertyAnimation>

using namespace std;


Admin::Admin(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Admin)
{
    ui->setupUi(this);
    ui->MI_AD->setHidden(true);
    animation = new QPropertyAnimation(ui->MIT_AD, "minimumWidth");
    managerooms();
    managetenants();
    manageservices();
    manageserviceusages();
    managereservations();
    managepayments();
    managecontracts();
    manageaccounts();
    manageroomtypes();
    managesta();
    ui->stackedWidget_2->setCurrentIndex(1);
    QAction *searchAction = new QAction(QIcon(":/new/prefix1/Resources/loupe.png"), "Search", this);
    ui->LineEditSearchRoom->addAction(searchAction, QLineEdit::LeadingPosition);

    // connect(ui->LineEditSearchTenant, &QLineEdit::returnPressed, this, [this]() {
    //     ui->searchtenant->click();
    // });
    // connect(ui->LineEditSearchRoom, &QLineEdit::returnPressed, this, [this]() {
    //     ui->searchroom->click();
    // });
    connect(ui->LineEditSearchPayment, &QLineEdit::returnPressed, this, [this]() {ui->searchPayment->click();});
    connect(ui->LineEditSearchRoom, &QLineEdit::textChanged, this, &Admin::searchroom);
    connect(ui->LineEditSearchTenant, &QLineEdit::textChanged, this, &Admin::searchtenant);
    connect(ui->LineEditSearchSer, &QLineEdit::textChanged, this, &Admin::searchSer);
    connect(ui->LineEditSearchSerUsage, &QLineEdit::textChanged, this, &Admin::searchSerUsage);
    connect(ui->LineEditSearchRe, &QLineEdit::textChanged, this, &Admin::searchRe);
    connect(ui->LineEditSearchRoomType, &QLineEdit::textChanged, this, &Admin::searchRoomType);

    //Nut sx Room
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
            Room::showAllRooms(this);
            if (ui->CBSR->currentIndex() == 4){
                sortButton->setIcon(QIcon(":/new/prefix1/Resources/sxgiam.png"));
                Room::Descending();
                ui->table1->clearContents();
                ui->table1->setRowCount(0);
                Room::searchByStatus(0, this);
            }
            if (ui->CBSR->currentIndex() == 5){
                sortButton->setIcon(QIcon(":/new/prefix1/Resources/sxgiam.png"));
                Room::Descending();
                ui->table1->clearContents();
                ui->table1->setRowCount(0);
                Room::searchByStatus(1, this);
            }
            if (ui->CBSR->currentIndex() == 6){
                sortButton->setIcon(QIcon(":/new/prefix1/Resources/sxgiam.png"));
                Room::Descending();
                ui->table1->clearContents();
                ui->table1->setRowCount(0);
                Room::searchByStatus(3, this);
            }
            if (ui->CBSR->currentIndex() == 7){
                sortButton->setIcon(QIcon(":/new/prefix1/Resources/sxgiam.png"));
                Room::Descending();
                ui->table1->clearContents();
                ui->table1->setRowCount(0);
                Room::searchByStatus(2, this);
            }
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
            if (ui->CBSR->currentIndex() == 3 && !ui->LineEditSearchRoom->text().isEmpty()){
                sortButton->setIcon(QIcon(":/new/prefix1/Resources/sxgiam.png"));
                Room::Descending();
                ui->table1->clearContents();
                ui->table1->setRowCount(0);
                Room::searchByName(ui->LineEditSearchRoom->text().toStdString(), this);
            }
        } else {
            sortButton->setIcon(QIcon(":/new/prefix1/Resources/sxtang.png"));
            Room::Ascending();
            ui->table1->clearContents();
            ui->table1->setRowCount(0);
            Room::showAllRooms(this);
            if (ui->CBSR->currentIndex() == 4){
                sortButton->setIcon(QIcon(":/new/prefix1/Resources/sxtang.png"));
                Room::Ascending();
                ui->table1->clearContents();
                ui->table1->setRowCount(0);
                Room::searchByStatus(0, this);
            }
            if (ui->CBSR->currentIndex() == 5){
                sortButton->setIcon(QIcon(":/new/prefix1/Resources/sxtang.png"));
                Room::Ascending();
                ui->table1->clearContents();
                ui->table1->setRowCount(0);
                Room::searchByStatus(1, this);
            }
            if (ui->CBSR->currentIndex() == 6){
                sortButton->setIcon(QIcon(":/new/prefix1/Resources/sxtang.png"));
                Room::Ascending();
                ui->table1->clearContents();
                ui->table1->setRowCount(0);
                Room::searchByStatus(3, this);
            }
            if (ui->CBSR->currentIndex() == 7){
                sortButton->setIcon(QIcon(":/new/prefix1/Resources/sxtang.png"));
                Room::Ascending();
                ui->table1->clearContents();
                ui->table1->setRowCount(0);
                Room::searchByStatus(2, this);
            }
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
            if (ui->CBSR->currentIndex() == 3 && !ui->LineEditSearchRoom->text().isEmpty()){
                sortButton->setIcon(QIcon(":/new/prefix1/Resources/sxtang.png"));
                Room::Ascending();
                ui->table1->clearContents();
                ui->table1->setRowCount(0);
                Room::searchByName(ui->LineEditSearchRoom->text().toStdString(), this);
            }
        }
    });
    // sx tenant id
    QRect headertenant = ui->TenantTable->visualRect(ui->TenantTable->model()->index(0, 0));
    QPushButton* sortIDTenantButton = new QPushButton(ui->TenantTable);
    sortIDTenantButton->setText("");
    sortIDTenantButton->setIcon(QIcon(":/new/prefix1/Resources/sxtang.png"));
    sortIDTenantButton->setFixedSize(16, 16);
    sortIDTenantButton->setToolTip("Sort by Room ID");
    sortIDTenantButton->move(headertenant.right() - 90, headertenant.top() + 3);
    sortIDTenantButton->setCheckable(true);
    connect(sortIDTenantButton, &QPushButton::toggled, this, [this, sortIDTenantButton](bool checked) {
        if (checked) {
            sortIDTenantButton->setIcon(QIcon(":/new/prefix1/Resources/sxgiam.png"));
            Tenant::sortID(false);
            ui->TenantTable->clearContents();
            ui->TenantTable->setRowCount(0);
            Tenant::showAllTenants(this);
            if (ui->CBST->currentIndex() == 3){
                sortIDTenantButton->setIcon(QIcon(":/new/prefix1/Resources/sxgiam.png"));
                Tenant::sortID(false);
                ui->TenantTable->clearContents();
                ui->TenantTable->setRowCount(0);
                Tenant::searchByGender(0, this);
            }
            if (ui->CBST->currentIndex() == 4){
                sortIDTenantButton->setIcon(QIcon(":/new/prefix1/Resources/sxgiam.png"));
                Tenant::sortID(false);
                ui->TenantTable->clearContents();
                ui->TenantTable->setRowCount(0);
                Tenant::searchByGender(1, this);
            }
            if (ui->CBST->currentIndex() == 1 && !ui->LineEditSearchTenant->text().isEmpty()){
                sortIDTenantButton->setIcon(QIcon(":/new/prefix1/Resources/sxgiam.png"));
                Tenant::sortID(false);
                ui->TenantTable->clearContents();
                ui->TenantTable->setRowCount(0);
                Tenant::searchByID(ui->LineEditSearchTenant->text().toStdString(), this);
            }
            if (ui->CBST->currentIndex() == 2 && !ui->LineEditSearchTenant->text().isEmpty()){
                sortIDTenantButton->setIcon(QIcon(":/new/prefix1/Resources/sxgiam.png"));
                Tenant::sortID(false);
                ui->TenantTable->clearContents();
                ui->TenantTable->setRowCount(0);
                Tenant::searchByName(ui->LineEditSearchTenant->text().toStdString(), this);
            }
        } else {
            sortIDTenantButton->setIcon(QIcon(":/new/prefix1/Resources/sxtang.png"));
            Tenant::sortID(true);
            ui->TenantTable->clearContents();
            ui->TenantTable->setRowCount(0);
            Tenant::showAllTenants(this);
            if (ui->CBST->currentIndex() == 3){
                sortIDTenantButton->setIcon(QIcon(":/new/prefix1/Resources/sxtang.png"));
                Tenant::sortID(true);
                ui->TenantTable->clearContents();
                ui->TenantTable->setRowCount(0);
                Tenant::searchByGender(0, this);
            }
            if (ui->CBST->currentIndex() == 4){
                sortIDTenantButton->setIcon(QIcon(":/new/prefix1/Resources/sxtang.png"));
                Tenant::sortID(true);
                ui->TenantTable->clearContents();
                ui->TenantTable->setRowCount(0);
                Tenant::searchByGender(1, this);
            }
            if (ui->CBST->currentIndex() == 1 && !ui->LineEditSearchTenant->text().isEmpty()){
                sortIDTenantButton->setIcon(QIcon(":/new/prefix1/Resources/sxtang.png"));
                Tenant::sortID(true);
                ui->TenantTable->clearContents();
                ui->TenantTable->setRowCount(0);
                Tenant::searchByID(ui->LineEditSearchTenant->text().toStdString(), this);
            }
            if (ui->CBST->currentIndex() == 2 && !ui->LineEditSearchTenant->text().isEmpty()){
                sortIDTenantButton->setIcon(QIcon(":/new/prefix1/Resources/sxtang.png"));
                Tenant::sortID(true);
                ui->TenantTable->clearContents();
                ui->TenantTable->setRowCount(0);
                Tenant::searchByName(ui->LineEditSearchTenant->text().toStdString(), this);
            }
        }
    });

// sx theo ten tenant
    QPushButton* sortNameTenantButton = new QPushButton(ui->TenantTable);
    sortNameTenantButton->setText("");
    sortNameTenantButton->setIcon(QIcon(":/new/prefix1/Resources/sxtang.png"));
    sortNameTenantButton->setFixedSize(16, 16);
    sortNameTenantButton->setToolTip("Sort by Room ID");
    sortNameTenantButton->move(headertenant.right() +25, headertenant.top() + 3);
    sortNameTenantButton->setCheckable(true);
    connect(sortNameTenantButton, &QPushButton::toggled, this, [this, sortNameTenantButton](bool checked) {
        if (checked) {
            sortNameTenantButton->setIcon(QIcon(":/new/prefix1/Resources/sxgiam.png"));
            Tenant::sortName(false);
            ui->TenantTable->clearContents();
            ui->TenantTable->setRowCount(0);
            Tenant::showAllTenants(this);
            if (ui->CBST->currentIndex() == 3){
                sortNameTenantButton->setIcon(QIcon(":/new/prefix1/Resources/sxgiam.png"));
                Tenant::sortName(false);
                ui->TenantTable->clearContents();
                ui->TenantTable->setRowCount(0);
                Tenant::searchByGender(0, this);
            }
            if (ui->CBST->currentIndex() == 4){
                sortNameTenantButton->setIcon(QIcon(":/new/prefix1/Resources/sxgiam.png"));
                Tenant::sortName(false);
                ui->TenantTable->clearContents();
                ui->TenantTable->setRowCount(0);
                Tenant::searchByGender(1, this);
            }
            if (ui->CBST->currentIndex() == 1 && !ui->LineEditSearchTenant->text().isEmpty()){
                sortNameTenantButton->setIcon(QIcon(":/new/prefix1/Resources/sxgiam.png"));
                Tenant::sortName(false);
                ui->TenantTable->clearContents();
                ui->TenantTable->setRowCount(0);
                Tenant::searchByID(ui->LineEditSearchTenant->text().toStdString(), this);
            }
            if (ui->CBST->currentIndex() == 2 && !ui->LineEditSearchTenant->text().isEmpty()){
                sortNameTenantButton->setIcon(QIcon(":/new/prefix1/Resources/sxgiam.png"));
                Tenant::sortName(false);
                ui->TenantTable->clearContents();
                ui->TenantTable->setRowCount(0);
                Tenant::searchByName(ui->LineEditSearchTenant->text().toStdString(), this);
            }
        } else {
            sortNameTenantButton->setIcon(QIcon(":/new/prefix1/Resources/sxtang.png"));
            Tenant::sortName(true);
            ui->TenantTable->clearContents();
            ui->TenantTable->setRowCount(0);
            Tenant::showAllTenants(this);
            if (ui->CBST->currentIndex() == 3){
                sortNameTenantButton->setIcon(QIcon(":/new/prefix1/Resources/sxtang.png"));
                Tenant::sortName(true);
                ui->TenantTable->clearContents();
                ui->TenantTable->setRowCount(0);
                Tenant::searchByGender(0, this);
            }
            if (ui->CBST->currentIndex() == 4){
                sortNameTenantButton->setIcon(QIcon(":/new/prefix1/Resources/sxtang.png"));
                Tenant::sortName(true);
                ui->TenantTable->clearContents();
                ui->TenantTable->setRowCount(0);
                Tenant::searchByGender(1, this);
            }
            if (ui->CBST->currentIndex() == 1 && !ui->LineEditSearchTenant->text().isEmpty()){
                sortNameTenantButton->setIcon(QIcon(":/new/prefix1/Resources/sxtang.png"));
                Tenant::sortName(true);
                ui->TenantTable->clearContents();
                ui->TenantTable->setRowCount(0);
                Tenant::searchByID(ui->LineEditSearchTenant->text().toStdString(), this);
            }
            if (ui->CBST->currentIndex() == 2 && !ui->LineEditSearchTenant->text().isEmpty()){
                sortNameTenantButton->setIcon(QIcon(":/new/prefix1/Resources/sxtang.png"));
                Tenant::sortName(true);
                ui->TenantTable->clearContents();
                ui->TenantTable->setRowCount(0);
                Tenant::searchByName(ui->LineEditSearchTenant->text().toStdString(), this);
            }
        }
    });
    //sx service id
    QRect headerSer = ui->SerTable->visualRect(ui->SerTable->model()->index(0, 0));
    QPushButton* sortidserviceButton = new QPushButton(ui->SerTable);
    sortidserviceButton->setText("");
    sortidserviceButton->setIcon(QIcon(":/new/prefix1/Resources/sxtang.png"));
    sortidserviceButton->setFixedSize(16, 16);
    sortidserviceButton->setToolTip("Sort by Room ID");
    sortidserviceButton->move(headerSer.right() - 85, headerSer.top() + 3);
    sortidserviceButton->setCheckable(true);
    connect(sortidserviceButton, &QPushButton::toggled, this, [this, sortidserviceButton](bool checked) {
        if (checked) {
            sortidserviceButton->setIcon(QIcon(":/new/prefix1/Resources/sxgiam.png"));
            Service::sortID(false);
            ui->SerTable->clearContents();
            ui->SerTable->setRowCount(0);
            Service::showAllServices(this);
            if (ui->CBSS->currentIndex() == 1 && !ui->LineEditSearchSer->text().isEmpty()){
                sortidserviceButton->setIcon(QIcon(":/new/prefix1/Resources/sxgiam.png"));
                Service::sortID(false);
                ui->SerTable->clearContents();
                ui->SerTable->setRowCount(0);
                Service::searchByID(ui->LineEditSearchSer->text().toStdString(), this);
            }
            if (ui->CBSS->currentIndex() == 2 && !ui->LineEditSearchSer->text().isEmpty()){
                sortidserviceButton->setIcon(QIcon(":/new/prefix1/Resources/sxgiam.png"));
                Service::sortID(false);
                ui->SerTable->clearContents();
                ui->SerTable->setRowCount(0);
                Service::searchByName(ui->LineEditSearchSer->text().toStdString(), this);
            }
        } else {
            sortidserviceButton->setIcon(QIcon(":/new/prefix1/Resources/sxtang.png"));
            Service::sortID(true);
            ui->SerTable->clearContents();
            ui->SerTable->setRowCount(0);
            Service::showAllServices(this);
            if (ui->CBSS->currentIndex() == 1 && !ui->LineEditSearchSer->text().isEmpty()){
                sortidserviceButton->setIcon(QIcon(":/new/prefix1/Resources/sxtang.png"));
                Service::sortID(true);
                ui->SerTable->clearContents();
                ui->SerTable->setRowCount(0);
                Service::searchByID(ui->LineEditSearchSer->text().toStdString(), this);
            }
            if (ui->CBSS->currentIndex() == 2 && !ui->LineEditSearchSer->text().isEmpty()){
                sortidserviceButton->setIcon(QIcon(":/new/prefix1/Resources/sxtang.png"));
                Service::sortID(true);
                ui->SerTable->clearContents();
                ui->SerTable->setRowCount(0);
                Service::searchByName(ui->LineEditSearchSer->text().toStdString(), this);
            }
        }
    });
    //sx serviceusage id
    QRect headerSerUsage = ui->SerUsageTable->visualRect(ui->SerUsageTable->model()->index(0, 0));
    QPushButton* sortidserviceusageButton = new QPushButton(ui->SerUsageTable);
    sortidserviceusageButton->setText("");
    sortidserviceusageButton->setIcon(QIcon(":/new/prefix1/Resources/sxtang.png"));
    sortidserviceusageButton->setFixedSize(16, 16);
    sortidserviceusageButton->setToolTip("Sort by Room ID");
    sortidserviceusageButton->move(headerSerUsage.right() - 75, headerSerUsage.top() + 3);
    sortidserviceusageButton->setCheckable(true);
    connect(sortidserviceusageButton, &QPushButton::toggled, this, [this, sortidserviceusageButton](bool checked) {
        if (checked) {
            sortidserviceusageButton->setIcon(QIcon(":/new/prefix1/Resources/sxgiam.png"));
            ServiceUsage::sortID(false);
            ui->SerUsageTable->clearContents();
            ui->SerUsageTable->setRowCount(0);
            ServiceUsage::showAllServiceUsages(this);
            if (ui->CBSSUsage->currentIndex() == 1 && !ui->LineEditSearchSerUsage->text().isEmpty()){
                sortidserviceusageButton->setIcon(QIcon(":/new/prefix1/Resources/sxgiam.png"));
                ServiceUsage::sortID(false);
                ui->SerUsageTable->clearContents();
                ui->SerUsageTable->setRowCount(0);
                ServiceUsage::searchByID(ui->LineEditSearchSerUsage->text().toStdString(), this);
            }
            if (ui->CBSSUsage->currentIndex() == 2 && !ui->LineEditSearchSerUsage->text().isEmpty()){
                sortidserviceusageButton->setIcon(QIcon(":/new/prefix1/Resources/sxgiam.png"));
                ServiceUsage::sortID(false);
                ui->SerUsageTable->clearContents();
                ui->SerUsageTable->setRowCount(0);
                ServiceUsage::searchByRoomID(ui->LineEditSearchSerUsage->text().toStdString(), this);
            }
        } else {
            sortidserviceusageButton->setIcon(QIcon(":/new/prefix1/Resources/sxtang.png"));
            ServiceUsage::sortID(true);
            ui->SerUsageTable->clearContents();
            ui->SerUsageTable->setRowCount(0);
            ServiceUsage::showAllServiceUsages(this);
            if (ui->CBSSUsage->currentIndex() == 1 && !ui->LineEditSearchSerUsage->text().isEmpty()){
                sortidserviceusageButton->setIcon(QIcon(":/new/prefix1/Resources/sxtang.png"));
                ServiceUsage::sortID(true);
                ui->SerUsageTable->clearContents();
                ui->SerUsageTable->setRowCount(0);
                ServiceUsage::searchByID(ui->LineEditSearchSerUsage->text().toStdString(), this);
            }
            if (ui->CBSSUsage->currentIndex() == 2 && !ui->LineEditSearchSerUsage->text().isEmpty()){
                sortidserviceusageButton->setIcon(QIcon(":/new/prefix1/Resources/sxtang.png"));
                ServiceUsage::sortID(true);
                ui->SerUsageTable->clearContents();
                ui->SerUsageTable->setRowCount(0);
                ServiceUsage::searchByRoomID(ui->LineEditSearchSerUsage->text().toStdString(), this);
            }
        }
    });
    //sx reservation
    QRect headerReservation = ui->ReservationTable->visualRect(ui->ReservationTable->model()->index(0, 0));
    QPushButton* sortidREButton = new QPushButton(ui->ReservationTable);
    sortidREButton->setText("");
    sortidREButton->setIcon(QIcon(":/new/prefix1/Resources/sxtang.png"));
    sortidREButton->setFixedSize(16, 16);
    sortidREButton->setToolTip("Sort by Room ID");
    sortidREButton->move(headerReservation.right() - 35, headerReservation.top() + 3);
    sortidREButton->setCheckable(true);
    connect(sortidREButton, &QPushButton::toggled, this, [this, sortidREButton](bool checked) {
        if (checked) {
            sortidREButton->setIcon(QIcon(":/new/prefix1/Resources/sxgiam.png"));
            Reservation::sortID(false);
            ui->ReservationTable->clearContents();
            ui->ReservationTable->setRowCount(0);
            Reservation::showAllReservations(this);
            if (ui->CBSRe->currentIndex() == 1 && !ui->LineEditSearchRe->text().isEmpty()){
                sortidREButton->setIcon(QIcon(":/new/prefix1/Resources/sxgiam.png"));
                Reservation::sortID(false);
                ui->ReservationTable->clearContents();
                ui->ReservationTable->setRowCount(0);
                Reservation::searchByID(ui->LineEditSearchRe->text().toStdString(), this);
            }
            if (ui->CBSRe->currentIndex() == 2){
                sortidREButton->setIcon(QIcon(":/new/prefix1/Resources/sxgiam.png"));
                Reservation::sortID(false);
                ui->ReservationTable->clearContents();
                ui->ReservationTable->setRowCount(0);
                Reservation::searchByStatus(1, this);
            }
            if (ui->CBSRe->currentIndex() == 3){
                sortidREButton->setIcon(QIcon(":/new/prefix1/Resources/sxgiam.png"));
                Reservation::sortID(false);
                ui->ReservationTable->clearContents();
                ui->ReservationTable->setRowCount(0);
                Reservation::searchByStatus(0, this);
            }
            if (ui->CBSRe->currentIndex() == 4){
                sortidREButton->setIcon(QIcon(":/new/prefix1/Resources/sxgiam.png"));
                Reservation::sortID(false);
                ui->ReservationTable->clearContents();
                ui->ReservationTable->setRowCount(0);
                Reservation::searchByStatus(2, this);
            }
        } else {
            sortidREButton->setIcon(QIcon(":/new/prefix1/Resources/sxtang.png"));
            Reservation::sortID(true);
            ui->ReservationTable->clearContents();
            ui->ReservationTable->setRowCount(0);
            Reservation::showAllReservations(this);
            if (ui->CBSRe->currentIndex() == 1 && !ui->LineEditSearchRe->text().isEmpty()){
                sortidREButton->setIcon(QIcon(":/new/prefix1/Resources/sxtang.png"));
                Reservation::sortID(true);
                ui->ReservationTable->clearContents();
                ui->ReservationTable->setRowCount(0);
                Reservation::searchByID(ui->LineEditSearchRe->text().toStdString(), this);
            }
            if (ui->CBSRe->currentIndex() == 2){
                sortidREButton->setIcon(QIcon(":/new/prefix1/Resources/sxtang.png"));
                Reservation::sortID(true);
                ui->ReservationTable->clearContents();
                ui->ReservationTable->setRowCount(0);
                Reservation::searchByStatus(1, this);
            }
            if (ui->CBSRe->currentIndex() == 3){
                sortidREButton->setIcon(QIcon(":/new/prefix1/Resources/sxtang.png"));
                Reservation::sortID(true);
                ui->ReservationTable->clearContents();
                ui->ReservationTable->setRowCount(0);
                Reservation::searchByStatus(0, this);
            }
            if (ui->CBSRe->currentIndex() == 4){
                sortidREButton->setIcon(QIcon(":/new/prefix1/Resources/sxtang.png"));
                Reservation::sortID(true);
                ui->ReservationTable->clearContents();
                ui->ReservationTable->setRowCount(0);
                Reservation::searchByStatus(2, this);
            }
        }
    });
    //sx contract
    QRect headerContract = ui->ContractTable->visualRect(ui->ContractTable->model()->index(0, 0));
    QPushButton* sortidContractButton = new QPushButton(ui->ContractTable);
    sortidContractButton->setText("");
    sortidContractButton->setIcon(QIcon(":/new/prefix1/Resources/sxtang.png"));
    sortidContractButton->setFixedSize(16, 16);
    sortidContractButton->setToolTip("Sort by Room ID");
    sortidContractButton->move(headerContract.right() - 30, headerContract.top() + 3);
    sortidContractButton->setCheckable(true);
    connect(sortidContractButton, &QPushButton::toggled, this, [this, sortidContractButton](bool checked) {
        if (checked) {
            sortidContractButton->setIcon(QIcon(":/new/prefix1/Resources/sxgiam.png"));
            Contract::sortID(false);
            ui->ContractTable->clearContents();
            ui->ContractTable->setRowCount(0);
            Contract::showAllContracts(this);
        } else {
            sortidContractButton->setIcon(QIcon(":/new/prefix1/Resources/sxtang.png"));
            Contract::sortID(true);
            ui->ContractTable->clearContents();
            ui->ContractTable->setRowCount(0);
            Contract::showAllContracts(this);
        }
    });
}
Admin::~Admin()
{
    delete ui;
    delete animation;
}
void Admin::moverMenu()
{
    int width = ui->MIT_AD->width();
    int normal = 71;
    int extender;

    if (width == 71) {
        extender = 245;
        QPropertyAnimation *animation = new QPropertyAnimation(ui->MIT_AD, "minimumWidth");
        ui->MI_AD->setVisible(false);
        ui->MIT_AD->setHidden(false);
        animation->setDuration(300);
        animation->setStartValue(width);
        animation->setEndValue(extender);
        animation->setEasingCurve(QEasingCurve::InOutQuart);
        animation->start(QAbstractAnimation::DeleteWhenStopped);
    } else {
        extender = normal;
        QPropertyAnimation *animation = new QPropertyAnimation(ui->MIT_AD, "minimumWidth");
        animation->setDuration(300);
        animation->setStartValue(width);
        animation->setEndValue(extender);
        animation->setEasingCurve(QEasingCurve::InOutQuart);
        connect(animation, &QPropertyAnimation::finished, this, [this]() {
            ui->MI_AD->setVisible(true);
            ui->MIT_AD->setHidden(true);
        });
        animation->start(QAbstractAnimation::DeleteWhenStopped);

    }
}

void Admin::managerooms(){
    Room::showAllRooms(this);
    ui->totalroom->setText(QString::number(Room::total));
    ui->table1->horizontalHeader()->setStyleSheet("QHeaderView::section { border: none; }");
    ui->table1->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
    ui->table1->horizontalHeaderItem(ui->table1->columnCount() - 1)->setTextAlignment(Qt::AlignCenter);
    ui->table1->setColumnWidth(0, 150);
    ui->table1->setColumnWidth(1, 150);
    ui->table1->setColumnWidth(2, 150);
    ui->table1->setColumnWidth(3, 150);
    ui->table1->setColumnWidth(4, 150);
    ui->table1->setColumnWidth(5, 150);
    // ui->table1->setColumnWidth(6, 150);
    ui->table1->verticalHeader()->hide();
}

void Admin::manageroomtypes(){
    RoomType::showAllRoomTypes(this);
    ui->totalservice->setText(QString::number(Service::total));
    // ui->RoomTypeTable->horizontalHeader()->setStyleSheet("QHeaderView::section { border: none; }");
    ui->RoomTypeTable->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
    ui->RoomTypeTable->horizontalHeaderItem(ui->RoomTypeTable->columnCount() - 1)->setTextAlignment(Qt::AlignCenter);
    ui->RoomTypeTable->setColumnWidth(0, 200);
    ui->RoomTypeTable->setColumnWidth(1, 200);
    ui->RoomTypeTable->setColumnWidth(2, 200);
    ui->RoomTypeTable->setColumnWidth(3, 200);
    ui->RoomTypeTable->setColumnWidth(4, 200);
    ui->RoomTypeTable->verticalHeader()->hide();
    ui->RoomTypeTable->setShowGrid(false);
}

void Admin::managetenants(){
    Tenant::showAllTenants(this);
    ui->totaltenant->setText(QString::number(Tenant::total));
    // ui->TenantTable->horizontalHeader()->setStyleSheet("QHeaderView::section { border: none; }");
    ui->TenantTable->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
    ui->TenantTable->horizontalHeaderItem(ui->TenantTable->columnCount() - 1)->setTextAlignment(Qt::AlignCenter);
    ui->TenantTable->setColumnWidth(0, 150);
    ui->TenantTable->setColumnWidth(1, 150);
    ui->TenantTable->setColumnWidth(2, 150);
    ui->TenantTable->setColumnWidth(3, 150);
    ui->TenantTable->setColumnWidth(4, 150);
    ui->TenantTable->setColumnWidth(5, 150);
    ui->TenantTable->verticalHeader()->hide();
    ui->TenantTable->setShowGrid(false);
}

void Admin::manageservices(){
    Service::showAllServices(this);
    ui->totalservice->setText(QString::number(Service::total));
    // ui->SerTable->horizontalHeader()->setStyleSheet("QHeaderView::section { border: none; }");
    ui->SerTable->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
    ui->SerTable->horizontalHeaderItem(ui->SerTable->columnCount() - 1)->setTextAlignment(Qt::AlignCenter);
    ui->SerTable->setColumnWidth(0, 200);
    ui->SerTable->setColumnWidth(1, 200);
    ui->SerTable->setColumnWidth(2, 200);
    ui->SerTable->setColumnWidth(3, 200);
    ui->SerTable->setColumnWidth(4, 200);
    ui->SerTable->verticalHeader()->hide();
    ui->SerTable->setShowGrid(false);
}

void Admin::manageserviceusages(){
    ServiceUsage::showAllServiceUsages(this);
    ui->totalserviceUsage->setText(QString::number(Service::total));
    // ui->SerUsageTable->horizontalHeader()->setStyleSheet("QHeaderView::section { border: none; }");
    ui->SerUsageTable->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
    // ui->SerUsageTable->horizontalHeaderItem(ui->SerUsageTable->columnCount() - 1)->setTextAlignment(Qt::AlignCenter);
    ui->SerUsageTable->setColumnWidth(0, 200);
    ui->SerUsageTable->setColumnWidth(1, 200);
    ui->SerUsageTable->setColumnWidth(2, 200);
    ui->SerUsageTable->setColumnWidth(3, 200);
    ui->SerUsageTable->setColumnWidth(4, 200);
    ui->SerUsageTable->setColumnWidth(5, 200);
    ui->SerUsageTable->verticalHeader()->hide();
    ui->SerUsageTable->setShowGrid(false);
    // QRect headerRect = ui->SerUsageTable->visualRect(ui->SerUsageTable->model()->index(0, 0));
}

void Admin::managereservations(){
    Reservation::showAllReservations(this);
    ui->totalserviceUsage->setText(QString::number(Service::total));
    // ui->ReservationTable->horizontalHeader()->setStyleSheet("QHeaderView::section { border: none; }");
    ui->ReservationTable->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
    ui->ReservationTable->horizontalHeaderItem(ui->ReservationTable->columnCount() - 1)->setTextAlignment(Qt::AlignCenter);
    ui->ReservationTable->setColumnWidth(0, 130);
    ui->ReservationTable->setColumnWidth(1, 130);
    ui->ReservationTable->setColumnWidth(2, 130);
    ui->ReservationTable->setColumnWidth(3, 130);
    ui->ReservationTable->setColumnWidth(4, 130);
    ui->ReservationTable->setColumnWidth(5, 130);
    ui->ReservationTable->verticalHeader()->hide();
    ui->ReservationTable->setShowGrid(false);
    // QRect headerRect = ui->ReservationTable->visualRect(ui->ReservationTable->model()->index(0, 0));
}

void Admin::managepayments(){
    Payment::showAllPayments(this);
    ui->PaymentTable->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
    ui->PaymentTable->horizontalHeaderItem(ui->PaymentTable->columnCount() - 1)->setTextAlignment(Qt::AlignCenter);
    ui->PaymentTable->verticalHeader()->hide();
    ui->PaymentTable->setShowGrid(false);
}

void Admin::managecontracts(){
    Contract::showAllContracts(this);
    ui->ContractTable->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
    ui->ContractTable->horizontalHeaderItem(ui->ContractTable->columnCount() - 1)->setTextAlignment(Qt::AlignCenter);
    ui->ContractTable->setColumnWidth(5, 50);
    ui->ContractTable->setColumnWidth(11, 50);
    ui->ContractTable->verticalHeader()->hide();
    ui->ContractTable->setShowGrid(false);
}

void Admin::manageaccounts(){
    Account::showAllAccount(this);
    ui->totalroom->setText(QString::number(Room::total));
    ui->AccountTable->horizontalHeader()->setStyleSheet("QHeaderView::section { border: none; }");
    ui->AccountTable->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
    // ui->AccountTable->horizontalHeaderItem(ui->AccountTable->columnCount() - 1)->setTextAlignment(Qt::AlignCenter);
    ui->AccountTable->setColumnWidth(0, 250);
    ui->AccountTable->setColumnWidth(1, 250);
    ui->AccountTable->setColumnWidth(2, 250);
    ui->AccountTable->setColumnWidth(3, 250);
    ui->AccountTable->setColumnWidth(4, 250);
    ui->AccountTable->verticalHeader()->hide();
}

void Admin::managesta(){
    ui->stackedWidgetSta->setCurrentIndex(0);
    drawchartMonths(2024);
    ui->MonthTable->horizontalHeader()->setStyleSheet("QHeaderView::section { border: none; }");
    ui->MonthTable->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
    // ui->MonthTable->horizontalHeaderItem(ui->AccountTable->columnCount() - 1)->setTextAlignment(Qt::AlignCenter);
    ui->MonthTable->verticalHeader()->hide();
    ui->MonthTable->setShowGrid(false);
    ui->YearTable->horizontalHeader()->setStyleSheet("QHeaderView::section { border: none; }");
    ui->YearTable->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
    // ui->YearTable->horizontalHeaderItem(ui->AccountTable->columnCount() - 1)->setTextAlignment(Qt::AlignCenter);
    ui->YearTable->verticalHeader()->hide();
    ui->YearTable->setShowGrid(false);
}

void Admin::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void Admin::on_pushButton_15_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}

void Admin::displayRooms(const Room& room) {
    string tenantName = "N/A";
    Tenant* tenant = Tenant::tenantList.searchID(room.tenant_ID);
    if (tenant != nullptr) {
        tenantName = tenant->getFullName();
    }
    int row = ui->table1->rowCount();
    ui->table1->insertRow(row);

    ui->table1->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(room.room_ID)));
    ui->table1->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(room.roomType->getID())));
    QString status;
    if (room.status==0) status = "Trống";
    else if (room.status==1) status = "Đang thuê";
    else if (room.status==3) status = "Đang bảo trì";
    else status = "Đã đặt";
    ui->table1->setItem(row, 2, new QTableWidgetItem(status));
    ui->table1->setItem(row, 3, new QTableWidgetItem(room.tenant_ID.empty() ? "N/A" : QString::fromStdString(room.getTenantID())));
    ui->table1->setItem(row, 4, new QTableWidgetItem(QString::fromStdString(tenantName)));
    ui->table1->setItem(row, 5, new QTableWidgetItem(QString::number(room.roomType->getPrice(), 'f', 2)));

    if (room.status == 0 || room.status == 3){
    QWidget* buttonWidget = new QWidget();
    QPushButton* editButton = new QPushButton();
    editButton->setIcon(QIcon(":/new/prefix1/Resources/edit.png"));
    editButton->setToolTip("Edit this room");
    connect(editButton, &QPushButton::clicked, this, [this, row]() {
        onEditButtonClicked(row);
    });

    QPushButton* deleteButton = new QPushButton();
    deleteButton->setIcon(QIcon(":/new/prefix1/Resources/delete.png"));
    deleteButton->setToolTip("Delete this room");
    connect(deleteButton, &QPushButton::clicked, this, [this, row]() {
        onDeleteButtonClicked(row);
    });

    QHBoxLayout* layout = new QHBoxLayout(buttonWidget);
    layout->addWidget(editButton);
    layout->addWidget(deleteButton);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);
    editButton->setFixedSize(20, 20);
    deleteButton->setFixedSize(20, 20);

    buttonWidget->setLayout(layout);

    ui->table1->setCellWidget(row, 6, buttonWidget);
    }
}

void Admin::displayRoomTypes(const RoomType& rt) {
    int row = ui->RoomTypeTable->rowCount();
    ui->RoomTypeTable->insertRow(row);

    ui->RoomTypeTable->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(rt.getID())));
    ui->RoomTypeTable->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(rt.getName())));
    ui->RoomTypeTable->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(rt.getDescription())));
    ui->RoomTypeTable->setItem(row, 3, new QTableWidgetItem(QString::number(rt.getPrice())));
    QWidget* buttonWidget = new QWidget();

    QPushButton* edit_RT_btn = new QPushButton();
    edit_RT_btn->setIcon(QIcon(":/new/prefix1/Resources/edit.png"));
    edit_RT_btn->setToolTip("Edit this room");
    connect(edit_RT_btn, &QPushButton::clicked, this, [this, row]() {
        onedit_RT_btnClicked(row);
    });

    QPushButton* delete_RT_btn = new QPushButton();
    delete_RT_btn->setIcon(QIcon(":/new/prefix1/Resources/delete.png"));
    delete_RT_btn->setToolTip("Delete this room");
    connect(delete_RT_btn, &QPushButton::clicked, this, [this, row]() {
        ondelete_RT_btnClicked(row);
    });

    QHBoxLayout* layout = new QHBoxLayout(buttonWidget);
    layout->addWidget(edit_RT_btn);
    layout->addWidget(delete_RT_btn);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);
    edit_RT_btn->setFixedSize(20, 20);
    delete_RT_btn->setFixedSize(20, 20);

    buttonWidget->setLayout(layout);

    ui->RoomTypeTable->setCellWidget(row, 4, buttonWidget);
}

void Admin::displayTenants(const Tenant& t) {
    int row = ui->TenantTable->rowCount();
    ui->TenantTable->insertRow(row);

    ui->TenantTable->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(t.tenant_ID)));
    ui->TenantTable->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(t.getFullName())));
    ui->TenantTable->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(t.phone)));
    ui->TenantTable->setItem(row, 3, new QTableWidgetItem(QString::number(t.getAge())));
    ui->TenantTable->setItem(row, 4, new QTableWidgetItem(QString::fromStdString(t.cccd)));
    ui->TenantTable->setItem(row, 5, new QTableWidgetItem(QString::fromStdString(t.gender ? "Nu" : "Nam")));
    QWidget* buttonWidget = new QWidget();

    QPushButton* edit_tenant_btn = new QPushButton();
    edit_tenant_btn->setIcon(QIcon(":/new/prefix1/Resources/edit.png"));
    edit_tenant_btn->setToolTip("Edit this room");
    connect(edit_tenant_btn, &QPushButton::clicked, this, [this, row]() {
        onedit_tenant_btnClicked(row);
    });

    QPushButton* delete_tenant_btn = new QPushButton();
    delete_tenant_btn->setIcon(QIcon(":/new/prefix1/Resources/delete.png"));
    delete_tenant_btn->setToolTip("Delete this room");
    connect(delete_tenant_btn, &QPushButton::clicked, this, [this, row]() {
        onDeleteButtonClicked(row);
    });

    QHBoxLayout* layout = new QHBoxLayout(buttonWidget);
    layout->addWidget(edit_tenant_btn);
    layout->addWidget(delete_tenant_btn);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);
    edit_tenant_btn->setFixedSize(20, 20);
    delete_tenant_btn->setFixedSize(20, 20);

    buttonWidget->setLayout(layout);

    ui->TenantTable->setCellWidget(row, 6, buttonWidget);
}

void Admin::displayServices(const Service& s) {
    int row = ui->SerTable->rowCount();
    ui->SerTable->insertRow(row);

    ui->SerTable->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(s.service_ID)));
    ui->SerTable->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(s.name)));
    ui->SerTable->setItem(row, 2, new QTableWidgetItem(QString::number(s.unit_price)));
    ui->SerTable->setItem(row, 3, new QTableWidgetItem(QString::fromStdString(s.description)));
    QWidget* buttonWidget = new QWidget();

    QPushButton* edit_Ser_btn = new QPushButton();
    edit_Ser_btn->setIcon(QIcon(":/new/prefix1/Resources/edit.png"));
    edit_Ser_btn->setToolTip("Edit this room");
    connect(edit_Ser_btn, &QPushButton::clicked, this, [this, row]() {
        onedit_Ser_btnClicked(row);
    });

    QPushButton* delete_Ser_btn = new QPushButton();
    delete_Ser_btn->setIcon(QIcon(":/new/prefix1/Resources/delete.png"));
    delete_Ser_btn->setToolTip("Delete this room");
    connect(delete_Ser_btn, &QPushButton::clicked, this, [this, row]() {
        ondelete_Ser_btnClicked(row);
    });

    QHBoxLayout* layout = new QHBoxLayout(buttonWidget);
    layout->addWidget(edit_Ser_btn);
    layout->addWidget(delete_Ser_btn);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);
    edit_Ser_btn->setFixedSize(20, 20);
    delete_Ser_btn->setFixedSize(20, 20);

    buttonWidget->setLayout(layout);

    ui->SerTable->setCellWidget(row, 4, buttonWidget);
}

void Admin::displayServiceUsages(const ServiceUsage& su){
    int row = ui->SerUsageTable->rowCount();
    ui->SerUsageTable->insertRow(row);

    ui->SerUsageTable->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(su.usage_ID)));
    ui->SerUsageTable->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(su.room_ID)));
    ui->SerUsageTable->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(su.service_ID)));
    ui->SerUsageTable->setItem(row, 3, new QTableWidgetItem(QString::fromStdString(su.tenantID)));
    ui->SerUsageTable->setItem(row, 4, new QTableWidgetItem(QString::fromStdString(su.status ? "Active" : "Inactive")));
}

void Admin::displayPayments(const Payment& p){
    int row = ui->PaymentTable->rowCount();
    ui->PaymentTable->insertRow(row);

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
    ui->PaymentTable->setItem(row, 10, new QTableWidgetItem(QString::number(p.getdepositAmount())));
    ui->PaymentTable->setItem(row, 11, new QTableWidgetItem(QString::number(p.getRemainingAmount())));
}

void Admin::displayContracts(const Contract& c){
    int row = ui->ContractTable->rowCount();
    ui->ContractTable->insertRow(row);
    Tenant* t = Tenant::tenantList.searchID(c.getTenantID());
    Room* r = Room::roomList.searchID(c.getRoomID());
    ui->ContractTable->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(c.getID())));
    ui->ContractTable->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(c.getRoomID())));
    ui->ContractTable->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(r->getRoomType()->getName())));
    ui->ContractTable->setItem(row, 3, new QTableWidgetItem(QString::fromStdString(c.getTenantID())));
    ui->ContractTable->setItem(row, 4, new QTableWidgetItem(QString::fromStdString(t->getFullName())));
    ui->ContractTable->setItem(row, 5, new QTableWidgetItem(QString::number(t->getAge())));
    ui->ContractTable->setItem(row, 6, new QTableWidgetItem(QString::fromStdString(t->getCCCD())));
    ui->ContractTable->setItem(row, 7, new QTableWidgetItem(QString::fromStdString(t->getPhone())));
    ui->ContractTable->setItem(row, 8, new QTableWidgetItem(QString::fromStdString(c.startDate.toString())));
    ui->ContractTable->setItem(row, 9, new QTableWidgetItem(QString::fromStdString(c.endDate.toString())));
    ui->ContractTable->setItem(row, 10, new QTableWidgetItem((QString("%1 VND/1 month").arg(QString::number(c.getrentprice(), 'f', 2)))));
    ui->ContractTable->setItem(row, 11, new QTableWidgetItem(QString::fromStdString(c.getStatus() == 1 ? "Active" : "Expired")));
    if (c.getStatus() == 1){
    QWidget* buttonWidget = new QWidget();

    QPushButton* terminate_btn = new QPushButton();
    terminate_btn->setIcon(QIcon(":/new/prefix1/Resources/rejectcontract.png"));
    terminate_btn->setToolTip("Hủy thuê");
    connect(terminate_btn, &QPushButton::clicked, this, [this, row]() {
        // onterminate_btnClicked(row);
    });

    QHBoxLayout* layout = new QHBoxLayout(buttonWidget);
    layout->addWidget(terminate_btn);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);
    terminate_btn->setFixedSize(20, 20);

    buttonWidget->setLayout(layout);

    ui->ContractTable->setCellWidget(row, 12, buttonWidget);
    }
}

void Admin::displayReservations(const Reservation& re) {
    QString statusText;
    QColor textColor;

    switch (re.status) {
    case 0:
        statusText = "Waiting";
        textColor = QColor(255, 165, 0);
        break;
    case 1:
        statusText = "Accepted";
        textColor = QColor("green");
        break;
    case 2:
        statusText = "Rejected";
        textColor = QColor("red");
        break;
    default:
        statusText = "Unknown";
        textColor = QColor("gray");
        break;
    }

    int row = ui->ReservationTable->rowCount();
    ui->ReservationTable->insertRow(row);

    ui->ReservationTable->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(re.reservation_ID)));
    ui->ReservationTable->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(re.room_ID)));
    ui->ReservationTable->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(re.tenant_ID)));
    ui->ReservationTable->setItem(row, 3, new QTableWidgetItem(QString::fromStdString(re.startDate.toString())));
    ui->ReservationTable->setItem(row, 4, new QTableWidgetItem(QString::fromStdString(re.endDate.toString())));

    QTableWidgetItem* statusItem = new QTableWidgetItem(statusText);
    QFont font = statusItem->font();
    font.setBold(true);
    statusItem->setFont(font);
    statusItem->setForeground(textColor);
    ui->ReservationTable->setItem(row, 5, statusItem);

    if (re.status == 0) {
        QWidget* buttonWidget = new QWidget();

        QPushButton* acceptbtn = new QPushButton();
        acceptbtn->setIcon(QIcon(":/new/prefix1/Resources/accept.png"));
        acceptbtn->setToolTip("Accept");
        connect(acceptbtn, &QPushButton::clicked, this, [this, row]() {
            onacceptbtnClicked(row);
        });

        QPushButton* rejectbtn = new QPushButton();
        rejectbtn->setIcon(QIcon(":/new/prefix1/Resources/decline.png"));
        rejectbtn->setToolTip("Reject");
        connect(rejectbtn, &QPushButton::clicked, this, [this, row]() {
            onrejectbtnClicked(row);
        });

        QHBoxLayout* layout = new QHBoxLayout(buttonWidget);
        layout->addWidget(acceptbtn);
        layout->addWidget(rejectbtn);
        layout->setContentsMargins(0, 0, 0, 0);
        layout->setSpacing(0);
        acceptbtn->setFixedSize(20, 20);
        rejectbtn->setFixedSize(20, 20);

        buttonWidget->setLayout(layout);

        ui->ReservationTable->setCellWidget(row, 6, buttonWidget);
    }
}

void Admin::displayAccounts(const Account& a){
    int row = ui->AccountTable->rowCount();
    ui->AccountTable->insertRow(row);

    ui->AccountTable->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(a.getID())));
    ui->AccountTable->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(a.getusername())));
    ui->AccountTable->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(a.getpassword())));
    ui->AccountTable->setItem(row, 3, new QTableWidgetItem(QString::fromStdString(a.gettenantID())));
    ui->AccountTable->setItem(row, 4, new QTableWidgetItem(QString::fromStdString(a.getrole() == 0 ? "Tenant" : "Admin")));
}
void Admin::onacceptbtnClicked(int row){
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Accept", "Are you sure you want to accept this?", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
    string id = ui->ReservationTable->item(row, 0)->text().toStdString();
    Contract::confirmReservationandcreatContract(1, id);
    ui->ReservationTable->clearContents();
    ui->ReservationTable->setRowCount(0);
    Reservation::showAllReservations(this);
    }
}

void Admin::onrejectbtnClicked(int row){
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Reject", "Are you sure you want to reject this?", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
    string id = ui->ReservationTable->item(row, 0)->text().toStdString();
    Contract::confirmReservationandcreatContract(2, id);
    ui->ReservationTable->clearContents();
    ui->ReservationTable->setRowCount(0);
    Reservation::showAllReservations(this);
    }
}

void Admin::onedit_tenant_btnClicked(int row){
    string tenantID = ui->TenantTable->item(row, 0)->text().toStdString();
    string name = ui->TenantTable->item(row, 1)->text().toStdString();
    string phone = ui->TenantTable->item(row, 2)->text().toStdString();
    int age = ui->TenantTable->item(row, 3)->text().toInt();
    string cccd = ui->TenantTable->item(row, 4)->text().toStdString();
    string gender = ui->TenantTable->item(row, 5)->text().toStdString();
    Edittenant tenantedit(tenantID, name, phone, age, cccd, gender, this);
    tenantedit.exec();
    ui->TenantTable->clearContents();
    ui->TenantTable->setRowCount(0);
    Tenant::showAllTenants(this);
    ui->totaltenant->setText(QString::number(Tenant::total));
}

void Admin::onedit_Ser_btnClicked(int row){
    string ID = ui->SerTable->item(row, 0)->text().toStdString();
    string name = ui->SerTable->item(row, 1)->text().toStdString();
    int price = ui->SerTable->item(row, 2)->text().toInt();
    string des = ui->SerTable->item(row, 3)->text().toStdString();
    Editservice edit(ID, name, price, des, this);
    edit.exec();
    ui->SerTable->clearContents();
    ui->SerTable->setRowCount(0);
    Service::showAllServices(this);
}

void Admin::onEditButtonClicked(int row) {
    string roomID = ui->table1->item(row, 0)->text().toStdString();
    Editroom roomedit(roomID, this);
    roomedit.exec();
    ui->table1->clearContents();
    ui->table1->setRowCount(0);
    Room::showAllRooms(this);
    ui->totalroom->setText(QString::number(Room::total));
}

void Admin::onedit_RT_btnClicked(int row){
    string id = ui->RoomTypeTable->item(row, 0)->text().toStdString();
    string name = ui->RoomTypeTable->item(row, 1)->text().toStdString();
    double price = ui->RoomTypeTable->item(row, 3)->text().toInt();
    string des = ui->RoomTypeTable->item(row, 2)->text().toStdString();
    Editroomtype edit(id, name, des, price, this);
    edit.exec();
    ui->RoomTypeTable->clearContents();
    ui->RoomTypeTable->setRowCount(0);
    RoomType::showAllRoomTypes(this);
}

void Admin::onDeleteButtonClicked(int row) {
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Delete", "Are you sure you want to delete this?", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
    string roomID = ui->table1->item(row, 0)->text().toStdString();
    Room::deleteRoom(roomID);
    ui->table1->clearContents();
    ui->table1->setRowCount(0);
    Room::showAllRooms(this);
    ui->totalroom->setText(QString::number(Room::total));
    }
}

void Admin::ondelete_Ser_btnClicked(int row){
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Delete", "Are you sure you want to delete this?", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        string ID = ui->SerTable->item(row, 0)->text().toStdString();
        Service::deleteService(ID);
        ui->SerTable->clearContents();
        ui->SerTable->setRowCount(0);
        Service::showAllServices(this);
        ui->totalservice->setText(QString::number(Service::total));
    }
}

void Admin::ondelete_RT_btnClicked(int row){
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Delete", "Are you sure you want to delete this?", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        string ID = ui->RoomTypeTable->item(row, 0)->text().toStdString();
        if (RoomType::isActive(ID)){
            QMessageBox::warning(this, "Delete", "Cannot delete, this room type is currently in use!");
            return;
        } else {
        RoomType::deleteRoomType(ID);
        ui->RoomTypeTable->clearContents();
        ui->RoomTypeTable->setRowCount(0);
        RoomType::showAllRoomTypes(this);
        ui->totalservice->setText(QString::number(Service::total));
        }
    }
}

void Admin::on_addroom_clicked()
{
    Addroom roomDialog(this);
    roomDialog.exec();
    ui->table1->clearContents();
    ui->table1->setRowCount(0);
    Room::showAllRooms(this);
    ui->totalroom->setText(QString::number(Room::total));
}

void Admin::searchroom()
{
    string search = ui->LineEditSearchRoom->text().toStdString();
    string check = ui->CBSR->currentText().toStdString();
    if (search.empty()) {
        ui->table1->clearContents();
        ui->table1->setRowCount(0);
        Room::showAllRooms(this);
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
        if (ui->CBSR->currentText() == "Tên khách thuê"){
            ui->table1->clearContents();
            ui->table1->setRowCount(0);
            Room::searchByName(search, this);
        }
}

void Admin::searchtenant()
{
    string search = ui->LineEditSearchTenant->text().toStdString();
    string check = ui->CBST->currentText().toStdString();
    if (search.empty()) {
        ui->TenantTable->clearContents();
        ui->TenantTable->setRowCount(0);
        Tenant::showAllTenants(this);
    }
    if (check == "Tenant ID"){
        ui->TenantTable->clearContents();
        ui->TenantTable->setRowCount(0);
        Tenant::searchByID(search, this);
    }
    if (check == "Tên"){
        ui->TenantTable->clearContents();
        ui->TenantTable->setRowCount(0);
        Tenant::searchByName(search, this);
    }
}
void Admin::searchSer()
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

void Admin::searchSerUsage(){
    string search = ui->LineEditSearchSerUsage->text().toStdString();
    string check = ui->CBSSUsage->currentText().toStdString();
    if (search.empty()){
        ui->SerUsageTable->clearContents();
        ui->SerUsageTable->setRowCount(0);
        ServiceUsage::showAllServiceUsages(this);
    }
    if (check == "Room ID"){
        ui->SerUsageTable->clearContents();
        ui->SerUsageTable->setRowCount(0);
        ServiceUsage::searchByRoomID(search, this);
    }
    if (check == "Service Usage ID"){
        ui->SerUsageTable->clearContents();
        ui->SerUsageTable->setRowCount(0);
        ServiceUsage::searchByID(search, this);
    }
}

void Admin::searchRe(){
    string search = ui->LineEditSearchRe->text().toStdString();
    string check = ui->CBSRe->currentText().toStdString();
    if (search.empty()){
        ui->ReservationTable->clearContents();
        ui->ReservationTable->setRowCount(0);
        Reservation::showAllReservations(this);
    }
    if (check == "Reservation ID"){
        ui->ReservationTable->clearContents();
        ui->ReservationTable->setRowCount(0);
        Reservation::searchByID(search, this);
    }
}

void Admin::searchRoomType(){
    string search = ui->LineEditSearchRoomType->text().toStdString();
    if (search.empty()){
        ui->RoomTypeTable->clearContents();
        ui->RoomTypeTable->setRowCount(0);
        RoomType::showAllRoomTypes(this);
    }
    if (ui->CBSRT->currentIndex() == 1){
        ui->RoomTypeTable->clearContents();
        ui->RoomTypeTable->setRowCount(0);
        RoomType::searchByID(search, this);
    }
    if (ui->CBSRT->currentIndex() == 2){
        ui->RoomTypeTable->clearContents();
        ui->RoomTypeTable->setRowCount(0);
        RoomType::searchByName(search, this);
    }
}
// void Admin::on_searchRer_clicked()
// {
//     string search = ui->LineEditSearchRe->text().toStdString();
//     ui->ReservationTable->clearContents();
//     ui->ReservationTable->setRowCount(0);
//     Reservation::searchByID(search, this);
// }


void Admin::on_CBSR_currentIndexChanged(int index)
{
    if (index == 0 || index == 4 || index == 5 || index == 6 || index == 7) {
        ui->LineEditSearchRoom->setEnabled(false);
        ui->LineEditSearchRoom->setStyleSheet("QLineEdit { background-color: #d3d3d3; padding-left:20px; border: 1px solid gray; border-radius: 10px; }");
    } else {
        ui->LineEditSearchRoom->setEnabled(true);
        ui->LineEditSearchRoom->setStyleSheet("QLineEdit {padding-left:20px; border: 1px solid gray; border-radius: 10px;}");
    }
    if (ui->CBSR->currentIndex() == 4){

        ui->table1->clearContents();
        ui->table1->setRowCount(0);
        ui->LineEditSearchRoom->clear();
        Room::searchByStatus(0, this);
    }
    if (ui->CBSR->currentIndex() == 5){

        ui->table1->clearContents();
        ui->table1->setRowCount(0);
        ui->LineEditSearchRoom->clear();
        Room::searchByStatus(1, this);
    }
    if (ui->CBSR->currentIndex() == 6){

        ui->table1->clearContents();
        ui->table1->setRowCount(0);
        ui->LineEditSearchRoom->clear();
        Room::searchByStatus(3, this);
    }
    if (ui->CBSR->currentIndex() ==  7){
        ui->table1->clearContents();
        ui->table1->setRowCount(0);
        ui->LineEditSearchRoom->clear();
        Room::searchByStatus(2, this);
    }
}

void Admin::on_pushButton_5_clicked()
{
    // Admin::moverMenu();
}


void Admin::on_DBbtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void Admin::on_DB1btn_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}




void Admin::on_Refbtn_clicked()
{
    ui->table1->clearContents();
    ui->table1->setRowCount(0);
    // managerooms();
    Room::showAllRooms(this);
    ui->LineEditSearchRoom->clear();
    ui->CBSR->setCurrentIndex(0);
}


void Admin::on_Tenantbtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void Admin::on_pushButton_17_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void Admin::on_RefTenantbtn_clicked()
{
    ui->TenantTable->clearContents();
    ui->TenantTable->setRowCount(0);
    Tenant::showAllTenants(this);
    ui->LineEditSearchTenant->clear();
    ui->CBST->setCurrentIndex(0);
}

void Admin::on_RefbtnSer_clicked()
{
    ui->SerTable->clearContents();
    ui->SerTable->setRowCount(0);
    Service::showAllServices(this);
    ui->LineEditSearchSer->clear();
    ui->CBSR->setCurrentIndex(0);
}


void Admin::on_Serbtn1_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void Admin::on_Serbtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void Admin::on_addSer_clicked()
{
    AddService add(this);
    add.exec();
    ui->SerTable->clearContents();
    ui->SerTable->setRowCount(0);
    Service::showAllServices(this);
    ui->totalservice->setText(QString::number(Service::total));
}



void Admin::on_SerUsage1btn_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}


void Admin::on_SerUsagebtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void Admin::on_ReservationUsagebtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}


void Admin::on_Reservation1btn_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void Admin::on_signoutbtn1_clicked()
{
    Login *login = new Login();
    login->show();
    this->close();
}


void Admin::on_signoutbtn_clicked()
{
    Login *login = new Login();
    login->show();
    this->close();
}




void Admin::on_Paymentbtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}


void Admin::on_Paymentbtn1_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}


void Admin::on_Contractbtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
}


void Admin::on_Contractbtn1_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
}


// void Admin::on_CBSRe_currentIndexChanged(int index)
// {
    // if (index == 0 || index == 2 || index == 3 || index == 4) {
        //         ui->LineEditSearchRe->setEnabled(false);
        //         ui->LineEditSearchRe->setStyleSheet("QLineEdit { background-color: #d3d3d3; padding-left:20px; border: 1px solid gray; border-radius: 10px; }");
        //     } else {
        //         ui->LineEditSearchRe->setEnabled(true);
        //         ui->LineEditSearchRe->setStyleSheet("QLineEdit {padding-left:20px; border: 1px solid gray; border-radius: 10px;}");
        //     }
        //     QString check = ui->CBSRe->currentText();
        //     if (check == "Phòng đang trống"){

        //         ui->table1->clearContents();
        //         ui->table1->setRowCount(0);
        //         ui->LineEditSearchRoom->clear();
        //         Room::searchByStatus(0, this);
        //     }
        //     if (check == "Phòng đã có người thuê"){

        //         ui->table1->clearContents();
        //         ui->table1->setRowCount(0);
        //         ui->LineEditSearchRoom->clear();
        //         Room::searchByStatus(1, this);
        //     }
        //     if (check == "Phòng đang bảo trì"){

        //         ui->table1->clearContents();
        //         ui->table1->setRowCount(0);
        //         ui->LineEditSearchRoom->clear();
        //         Room::searchByStatus(3, this);
        //     }
        //     if (check == "Phòng đã đặt"){
        //         ui->table1->clearContents();
        //         ui->table1->setRowCount(0);
        //         ui->LineEditSearchRoom->clear();
        //         Room::searchByStatus(2, this);
        //     }
// }


void Admin::on_searchPayment_clicked()
{
    int month = ui->CBSP->currentText().toInt();
    int year = ui->LineEditSearchPayment->text().toInt();
    ui->PaymentTable->clearContents();
    ui->PaymentTable->setRowCount(0);
    Payment::searchByMonth(month, year, this);
}


void Admin::on_RefPaymentbtn_clicked()
{
    ui->PaymentTable->clearContents();
    ui->PaymentTable->setRowCount(0);
    Payment::showAllPayments(this);
    ui->LineEditSearchPayment->clear();
    ui->CBSR->setCurrentIndex(0);
}


void Admin::on_CBST_currentIndexChanged(int index)
{
    if (index == 0 || index == 3 || index == 4) {
        ui->LineEditSearchTenant->setEnabled(false);
        ui->LineEditSearchTenant->setStyleSheet("QLineEdit { background-color: #d3d3d3; padding-left:20px; border: 1px solid gray; border-radius: 10px; }");
    } else {
        ui->LineEditSearchTenant->setEnabled(true);
        ui->LineEditSearchTenant->setStyleSheet("QLineEdit {padding-left:20px; border: 1px solid gray; border-radius: 10px;}");
    }
    QString check = ui->CBST->currentText();
    if (check == "Nam"){
        ui->TenantTable->clearContents();
        ui->TenantTable->setRowCount(0);
        ui->LineEditSearchTenant->clear();
        Tenant::searchByGender(0, this);
    }
    if (check == "Nữ"){
        ui->TenantTable->clearContents();
        ui->TenantTable->setRowCount(0);
        ui->LineEditSearchTenant->clear();
        Tenant::searchByGender(1, this);
    }
}


void Admin::on_CBSRe_currentIndexChanged(int index)
{
    if (index == 0 || index == 2 || index == 3 || index == 4) {
        ui->LineEditSearchRe->setEnabled(false);
        ui->LineEditSearchRe->setStyleSheet("QLineEdit { background-color: #d3d3d3; padding-left:20px; border: 1px solid gray; border-radius: 10px; }");
    } else {
        ui->LineEditSearchRe->setEnabled(true);
        ui->LineEditSearchRe->setStyleSheet("QLineEdit {padding-left:20px; border: 1px solid gray; border-radius: 10px;}");
    }
    QString check = ui->CBSRe->currentText();
    if (check == "Accepted"){
        ui->ReservationTable->clearContents();
        ui->ReservationTable->setRowCount(0);
        Reservation::searchByStatus(1, this);
    }
    if (check == "Waiting"){
        ui->ReservationTable->clearContents();
        ui->ReservationTable->setRowCount(0);
        Reservation::searchByStatus(0, this);
    }
    if (check == "Rejected"){
        ui->ReservationTable->clearContents();
        ui->ReservationTable->setRowCount(0);
        Reservation::searchByStatus(2, this);
    }
}


void Admin::on_Accountbtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}


void Admin::on_Accountbtn1_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}


void Admin::on_RoomTypebtn1_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);
}


void Admin::on_RoomTypebtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);
}

void Admin::drawchartMonths(int year){

    QVBoxLayout *layout = qobject_cast<QVBoxLayout*>(ui->widgetchart->layout());

    if (layout) {
        QLayoutItem *item;
        while ((item = layout->takeAt(0)) != nullptr) {
            delete item->widget();
            delete item;
        }
    } else {
        layout = new QVBoxLayout(ui->widgetchart);
    }

    QChart *chart = new QChart();
    PaymentStatistics::showMonthlyComparison(year, chart, this);
    QChartView *chartview = new QChartView(chart);
    chartview->setRenderHint(QPainter::Antialiasing);


    layout->addWidget(chartview);
    ui->widgetchart->setLayout(layout);
}

void Admin::drawchartYears(int start, int end){
    QVBoxLayout *layout = qobject_cast<QVBoxLayout*>(ui->widgetchart->layout());

    if (layout) {
        QLayoutItem *item;
        while ((item = layout->takeAt(0)) != nullptr) {
            delete item->widget();
            delete item;
        }
    } else {
        layout = new QVBoxLayout(ui->widgetchart);
    }

    QChart *chart = new QChart();
    PaymentStatistics::showYearlyComparison(start, end, chart, this);
    QChartView *chartview = new QChartView(chart);
    chartview->setRenderHint(QPainter::Antialiasing);


    layout->addWidget(chartview);
    ui->widgetchart->setLayout(layout);
}

void Admin::on_Statisticsbtn1_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}


void Admin::on_Statisticsbtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}


void Admin::on_TKbtn_clicked()
{
    if(ui->comboBoxTK->currentIndex() == 0){
        ui->MonthTable->clearContents();
        ui->MonthTable->setRowCount(0);
        ui->stackedWidgetSta->setCurrentIndex(0);
        int year = ui->TK3year->text().toInt();
        drawchartMonths(year);
    }
    if(ui->comboBoxTK->currentIndex() == 1){
        ui->YearTable->clearContents();
        ui->YearTable->setRowCount(0);
        ui->stackedWidgetSta->setCurrentIndex(1);
        int start = ui->TK2year1->text().toInt();
        int end = ui->TK2year2->text().toInt();
        if (end - start > 15){
        QMessageBox::warning(this, "Warning", "Giới hạn các năm cách nhau không quá 15 năm");
            return;
        }
        drawchartYears(start, end);
    }
}


void Admin::on_comboBoxTK_currentIndexChanged(int index)
{
    if (index == 0){
        ui->stackedWidget_2->setCurrentIndex(1);
    }
    if (index == 1){
        ui->stackedWidget_2->setCurrentIndex(0);
    }
}


void Admin::on_CreatePaymentbtn_clicked()
{
    Createpayment payment(this);
    payment.exec();
    ui->PaymentTable->clearContents();
    ui->PaymentTable->setRowCount(0);
    Payment::showAllPayments(this);
}

void Admin::displayMonthlyComparison(int month, double tb, double tc, double t){
    int row = ui->MonthTable->rowCount();
    ui->MonthTable->insertRow(row);

    ui->MonthTable->setItem(row, 0, new QTableWidgetItem(QString::number(month)));
    ui->MonthTable->setItem(row, 1, new QTableWidgetItem(QString::number(tb, 'f', 2)));
    ui->MonthTable->setItem(row, 2, new QTableWidgetItem(QString::number(tc, 'f', 2)));
    ui->MonthTable->setItem(row, 3, new QTableWidgetItem(QString::number(t, 'f', 2)));
}

void Admin::displayYearlyComparison(int year, double tb, double tc, double t){
    int row = ui->YearTable->rowCount();
    ui->YearTable->insertRow(row);

    ui->YearTable->setItem(row, 0, new QTableWidgetItem(QString::number(year)));
    ui->YearTable->setItem(row, 1, new QTableWidgetItem(QString::number(tb, 'f', 2)));
    ui->YearTable->setItem(row, 2, new QTableWidgetItem(QString::number(tc, 'f', 2)));
    ui->YearTable->setItem(row, 3, new QTableWidgetItem(QString::number(t, 'f', 2)));
}
