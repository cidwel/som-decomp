; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-slot-descriptions.md.
.setcpu "65816"
.smart
.a8
.i16

derive_selected_save_slot_primary_or_backup_offset = $5D00

.segment "CODE"
.org $5B25
read_native_saved_slot_character_level:
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
    lda f:$306104,X
    inc
    .a16
    and #$00FF
    plx
    tay
    sep #$20
    rts
