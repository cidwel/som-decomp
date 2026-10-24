; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-pause.md.
.setcpu "65816"
.smart
.a8
.i16

clear_map_menu_workspace = $C01063
reset_map_menu_state = $C00EBF

.segment "CODE"
.org $0FE1
close_temporary_dialogue_and_reset_message_workspace:
    phb
    .a8
    lda #$7E
    pha
    plb
    jsl f:reset_map_menu_state
    .a8
    lda #$00
    sta a:$A162
    .a8
    lda #$50
    sta a:$A170
    jsl f:clear_map_menu_workspace
    plb
    rts
