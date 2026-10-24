; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-scroll.md.
.setcpu "65816"
.smart
.a8
.i16

initialize_scrolling_dialogue_sprite_workspace = $481F

.segment "CODE"
.org $0030
initialize_scrolling_dialogue_sprite_workspace_long:
    jsr initialize_scrolling_dialogue_sprite_workspace
    rtl
