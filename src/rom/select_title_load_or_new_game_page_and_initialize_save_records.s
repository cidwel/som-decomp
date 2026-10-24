; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-title-callbacks.md.
.setcpu "65816"
.smart
.a8
.i16

initialize_native_party_name_entry_records = $51C2
initialize_new_game_save_records_public_jump = $C00030

.segment "CODE"
.org $5F4A
select_title_load_or_new_game_page_and_initialize_save_records:
    jsr initialize_native_party_name_entry_records
    lda f:$307FFF
    .a8
    cmp #$04
    bcc select_title_load_or_new_game_page_and_initialize_save_records_c75f5b
    .a8
    lda #$00
    sta f:$307FFF
select_title_load_or_new_game_page_and_initialize_save_records_c75f5b:
    .a8
    lda #$02
    xba
    lda a:$A211
    bne select_title_load_or_new_game_page_and_initialize_save_records_c75f7a
    .i16
    ldx #$0100
    .a8
    lda #$00
select_title_load_or_new_game_page_and_initialize_save_records_c75f68:
    sta a:$CEFF,X
    dex
    bne select_title_load_or_new_game_page_and_initialize_save_records_c75f68
    php
    jsl f:initialize_new_game_save_records_public_jump
    plp
    .i16
    ldy #$0000
    .a8
    lda #$03
    xba
select_title_load_or_new_game_page_and_initialize_save_records_c75f7a:
    xba
    sta a:$A210
    stz a:$A211
    .a8
    lda #$01
    tsb a:$A20A
    rtl
