; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-text-tick.md.
.setcpu "65816"
.smart
.a8
.i16

calculate_wrapped_native_menu_row_index = $C06BE2
dispatch_native_menu_second_line_description = $D5F3
run_native_dialogue_public_jump = $C00092
select_complete_native_menu_description_script = $D3F0
set_native_menu_dialogue_script_and_close_prior_window = $D5D7

.segment "CODE"
.org $D397
prepare_and_run_complete_native_menu_dialogue_frame:
    phx
    phy
    php
    sep #$20
    .a8
    lda #$04
    bit a:$1802
    beq prepare_and_run_complete_native_menu_dialogue_frame_d0d3da
    trb a:$1802
    lda a:$1803
    .a8
    bit #$10
    bne prepare_and_run_complete_native_menu_dialogue_frame_d0d3da
    rep #$30
    .a16
    lda #$527F
    sta a:$19D0
    .a16
    lda #$0055
    sta a:$19D2
    stz a:$19D4
    jsl f:calculate_wrapped_native_menu_row_index
    sep #$20
    sta a:$19D3
    jsr select_complete_native_menu_description_script
    jsr dispatch_native_menu_second_line_description
    rep #$30
    .i16
    ldx #$19D0
    .a16
    lda #$0000
    jsr set_native_menu_dialogue_script_and_close_prior_window
    bra prepare_and_run_complete_native_menu_dialogue_frame_d0d3e3
prepare_and_run_complete_native_menu_dialogue_frame_d0d3da:
    sep #$20
    .a8
    lda #$01
    bit a:$1D04
    beq prepare_and_run_complete_native_menu_dialogue_frame_d0d3ec
prepare_and_run_complete_native_menu_dialogue_frame_d0d3e3:
    sep #$20
    stz a:$1D13
    jsl f:run_native_dialogue_public_jump
prepare_and_run_complete_native_menu_dialogue_frame_d0d3ec:
    plp
    ply
    plx
    rtl
