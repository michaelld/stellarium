/*
 * Stellarium
 * Copyright (C) 2014 Marcos Cardinot
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Suite 500, Boston, MA  02110-1335, USA.
*/

#include "AddOnWidget.hpp"
#include "ui_addonWidget.h"

AddOnWidget::AddOnWidget(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui_AddOnWidget)
	, m_pStelAddOnDAO(StelApp::getInstance().getStelAddOnMgr().getStelAddOnDAO())
{
	ui->setupUi(this);
}

AddOnWidget::~AddOnWidget()
{
	delete ui;
	ui = NULL;
}

void AddOnWidget::init(int addonId)
{
	StelAddOnDAO::WidgetInfo info = m_pStelAddOnDAO->getAddOnWidgetInfo(addonId);
	ui->txtAuthor->setText(info.a1Name);
	ui->txtDescription->setText(info.description);
}
