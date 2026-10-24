; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-saved-game-menu-request.md.
.setcpu "65816"
.smart
.a8
.i16

derive_selected_save_slot_primary_or_backup_offset = $5D00

.segment "CODE"
.org $5BA8
read_second_native_saved_hero_confirmation_statistic:
    rep #$20
    phx
    jsr derive_selected_save_slot_primary_or_backup_offset
    stx a:$A171
    lda a:$A177
    .a16
    and #$00FF
    xba
    lsr
    clc
    adc a:$A171
    tax
    lda f:$30610A,X
    .a16
    and #$00FF
    plx
    tay
    sep #$20
    rts
