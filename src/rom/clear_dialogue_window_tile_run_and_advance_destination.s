; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-render-core.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $0435
clear_dialogue_window_tile_run_and_advance_destination:
    .a8
    lda #$20
    xba
    lda a:$A162
    .a8
    cmp #$03
    bne clear_dialogue_window_tile_run_and_advance_destination_c00442
    .a8
    lda #$60
    xba
clear_dialogue_window_tile_run_and_advance_destination_c00442:
    xba
clear_dialogue_window_tile_run_and_advance_destination_c00443:
    stz a:$9400,X
    inx
    dec
    bne clear_dialogue_window_tile_run_and_advance_destination_c00443
    txy
    rts
