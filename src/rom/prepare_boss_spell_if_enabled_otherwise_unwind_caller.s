; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-attack-selection.md.
.setcpu "65816"
.smart
.a8
.i16

prepare_boss_spell_targets = $396D

.segment "CODE"
.org $5906
prepare_boss_spell_if_enabled_otherwise_unwind_caller:
    ldx $87
    sta $00
    sep #$20
    lda a:$0186,X
    rep #$20
    beq prepare_boss_spell_if_enabled_otherwise_unwind_caller_c2591e
    lda $00
    jsr prepare_boss_spell_targets
    lda $87
    sta a:$0360
    rts
prepare_boss_spell_if_enabled_otherwise_unwind_caller_c2591e:
    pla
    rts
