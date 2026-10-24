; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-saved-game-menu-request.md.
.setcpu "65816"
.smart
.a8
.i16

derive_selected_save_slot_primary_or_backup_offset = $5D00
routine_c75ed8 = $5ED8
routine_c75edc = $5EDC
routine_c75eeb = $5EEB

.segment "CODE"
.org $5E95
append_three_present_native_saved_hero_portraits:
    lda a:$A216
    .a8
    and #$03
    .a8
    eor #$03
    beq append_three_present_native_saved_hero_portraits_c75ec7
    rep #$20
    jsr derive_selected_save_slot_primary_or_backup_offset
    sep #$20
    lda f:$306283,X
    phx
    dec
    bne append_three_present_native_saved_hero_portraits_c75eb0
    jsr routine_c75ed8
append_three_present_native_saved_hero_portraits_c75eb0:
    plx
    lda f:$306289,X
    phx
    dec
    bne append_three_present_native_saved_hero_portraits_c75ebc
    jsr routine_c75edc
append_three_present_native_saved_hero_portraits_c75ebc:
    plx
    lda f:$30628F,X
    dec
    bne append_three_present_native_saved_hero_portraits_c75ec7
    jsr routine_c75eeb
append_three_present_native_saved_hero_portraits_c75ec7:
    rts
