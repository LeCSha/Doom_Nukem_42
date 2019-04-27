/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom_d_menu.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaille <abaille@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 13:12:49 by abaille           #+#    #+#             */
/*   Updated: 2019/04/26 21:08:59 by abaille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOM_D_MENU_H
# define DOOM_D_MENU_H

# define NB_IMG_MENU	13
# define NB_BLOC_NG		4
# define NB_BLOC_IG		4
# define NB_OPT_KEY		15
# define NB_OPT_MENU	17
# define NB_INTER_STR	18
/*
** MENU Index IMG - title
*/
# define I_IHOME		0
# define I_IMAINMENU	1
# define I_IOPT			2
# define I_INGAME		3
# define I_LOADMENU		4
# define I_IBTN			5
# define I_INEWGAME		6
# define I_INTER1		7
# define I_INTER2		8
# define I_INTER3		9
# define I_END1			10
# define I_END2			11
# define I_END3			12

/*
** MENU String
*/
# define S_MAINMENU		"MAIN MENU"
# define S_NEWGAME		"NEW GAME"
# define S_LOADGAME		"LOAD GAME"
# define S_OPTIONS		"SETTINGS"
# define S_SAVE			"SAVE"
# define S_QUIT			"QUIT"
# define S_RETURN		"Return"
# define S_RESET		"Reset keys"

/*
** OPTIONS string
*/
# define S_OUP			"UP     		  	    	 : "
# define S_ODOWN		"DOWN       	    : "
# define S_OLEFT		"RIFT LEFT       : "
# define S_ORIGHT		"RIFT RIGHT   : "
# define S_OJUMP		"JUMP       	       : "
# define S_ODUCK		"DUCK       	      : "
# define S_OINVENTR		"INVENTORY  : "
# define S_OPICK		"PICK/OPEN	 	     		: "
# define S_ORELOAD		"LOAD WPN   	 	   		: "
# define S_OJETPACKON	"JETPACK ON/OFF  : "
# define S_OBLUEGEM		"BLUE GEM       		 	    : "
# define S_OGREEGEM		"GREEN GEM     		  	 : "
# define S_OREDGEM		"RED GEM       	    		   : "
# define S_OPURPGEM		"PURPLE GEM          	 : "

/*
** OPTIONS Index options
*/
# define I_OON			0
# define I_OUP			1
# define I_ODOWN		2
# define I_OLEFT		3
# define I_ORIGHT		4
# define I_OJUMP		5
# define I_ODUCK		6
# define I_OINVENTR		7
# define I_OPICKOPN		8
# define I_ORELOAD		9
# define I_OJETPACKON	10
# define I_OBLUEGEM		11
# define I_OGREEGEM		12
# define I_OREDGEM		13
# define I_OPURPGEM		14

/*
** INTER intro str
*/
# define S_INTRO1_1	"Doom has come... Only you can send all the demons back to Hell.."
# define S_INTRO1_2	"Killing them all is the only way to success.."
# define S_INTRO1_3	"They are rage, brutal, without mercy. But you. You will be worse. Rip and tear, until it is done."
# define S_INTRO2_1	"It seems like someone did'nt entirely get what he deserved.."
# define S_INTRO2_2	"MECHA-FUHRER's been brought back from the dead with only one goal: to stop you."
# define S_INTRO2_3	"Don't let him.."
# define S_INTRO3_1	"Now you're at the CYBER DEMON's gates.. He's waiting for you.."
# define S_INTRO3_2	"You'd better be prepared for what's coming.."
# define S_INTRO3_3	"Take him down, and we all might live long enough to see the sun rise.."
# define S_END1_1	"Not bad.."
# define S_END1_2	"This was only a warm-up."
# define S_END1_3	"Now the real game begins.."
# define S_END2_1	"You're impressive, I give you that.. But don't rest yet."
# define S_END2_2	"There is still plenty to do.."
# define S_END2_3	"And many to kill."
# define S_END3_1	"Well.. You did it.."
# define S_END3_2	"Not that surprising, we expected nothing less from the Duke.."
# define S_END3_3	"Come at the Corp and meet the Conseil, it's time to get your... paiement."
/*
** INTRO str index
*/
# define I_INTRO1_1	0
# define I_INTRO2_1	3
# define I_INTRO3_1	6
# define I_END1_1	9
# define I_END2_1	12
# define I_END3_1	15

#endif
