/***************************************************************************
 *  CreateVoiceCommand.cpp
 *  2012  Florent Berthaut
 *  hitmuri.net
 ****************************************************************************/

/*
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */
 
#include "CreateVoiceCommand.hpp"
#include "../GppSound.hpp"

CreateVoiceCommand::CreateVoiceCommand(const unsigned int& id, 
										GppSound* perc): 
											UpdateVoiceCommand(id, perc){
    m_voice=new Voice(m_voiceID);
}

CreateVoiceCommand::~CreateVoiceCommand() {

}

void CreateVoiceCommand::run() {
    m_perc->addVoice(m_voiceID, m_voice);
    UpdateVoiceCommand::run();
}

AudioCommand* CreateVoiceCommand::clone() {
	return new CreateVoiceCommand(m_voiceID, m_perc);
}


