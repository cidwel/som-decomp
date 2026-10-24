; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $AEF4
copy_actor_velocity_presets_to_wram:
    phb
    rep #$30
    .i16
    ldx #$AF05
    .i16
    ldy #$C700
    .a16
    lda #$006F
    mvn #$02, #$7E
    plb
    rtl
