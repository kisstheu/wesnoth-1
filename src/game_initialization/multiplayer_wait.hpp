/*
   Copyright (C) 2007 - 2016 by David White <dave@whitevine.net>
   Part of the Battle for Wesnoth Project http://www.wesnoth.org

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY.

   See the COPYING file for more details.
*/

#ifndef MULTIPLAYER_WAIT_HPP_INCLUDED
#define MULTIPLAYER_WAIT_HPP_INCLUDED

#include "flg_manager.hpp"
#include "multiplayer_ui.hpp"
#include "widgets/combo.hpp"
#include "show_dialog.hpp" //gui::preview_pane

namespace mp {

class wait : public ui
{
public:
	wait(CVideo& v, twesnothd_connection* wesnothd_connection, const config& cfg, saved_game& state, chat& c,
		config& gamelist, const bool first_scenario = true);
	~wait();
	virtual void process_event();

	void join_game(bool observe);

	void start_game();

protected:
	virtual void layout_children(const SDL_Rect& rect);
	virtual void hide_children(bool hide=true);
	virtual void process_network_data(const config& data);

private:
	void generate_menu();
	bool download_level_data();
	config& get_scenario();
	const config& get_scenario() const;

	gui::button cancel_button_;
	gui::label start_label_;
	gui::menu game_menu_;

	config level_;
	saved_game& state_;

	const bool first_scenario_;
	bool stop_updates_;

	void process_event_impl(bool);
};

}
#endif
