/*
 * OldSchoolHack GUI
 *
 * Copyright (c) 2012 KN4CK3R http://www.oldschoolhack.de
 *
 * See license in OSHGui.hpp
 */

#ifndef OSHGUI_EVENT_KEYBOARDMESSAGE_HPP
#define OSHGUI_EVENT_KEYBOARDMESSAGE_HPP

#include "Key.hpp"
#include "../Misc/Strings.hpp"

namespace OSHGui
{
	/**
	 * Tastaturevent
	 */
	class OSHGUI_EXPORT KeyboardMessage
	{
	public:
		enum KeyboardStates
		{
			/**
			 * Unbekannt
			 */
			Unknown,
			/**
			 * Taste wurde gedr�ckt
			 */
			KeyDown,
			/**
			 * enth�lt das Zeichen der gedr�ckten Taste
			 */
			Character,
			/**
			 * Taste wurde losgelassen
			 */
			KeyUp
		};

		KeyboardStates State;
		Key::Keys KeyCode;
		Misc::AnsiChar KeyChar;
		Key::Keys Modifier;
		
	public:
		/**
		 * Konstruktor der Klasse.
		 */
		KeyboardMessage()
		{
			State = Unknown;
			KeyCode = Key::None;
			KeyChar = '\0';
			Modifier = Key::None;
		}

		/**
		 * Pr�ft, ob das Zeichen alphanumerisch ist.
		 *
		 * @return ja / nein
		 */
		bool IsAlphaNumeric() const
		{
			return Misc::String::IsLetterOrDigit(KeyChar)
				|| Misc::String::IsPunctuation(KeyChar)
				|| Misc::String::IsSeperator(KeyChar)
				|| Misc::String::IsSymbol(KeyChar);
		}
	};
}

#endif