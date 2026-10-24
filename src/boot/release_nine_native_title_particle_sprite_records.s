; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-title-particle-stop.md.
.setcpu "65816"
.smart
.a8
.i16

routine_7eb786 = $B786

.segment "CODE"
.org $97EF
release_nine_native_title_particle_sprite_records:
    php
    sep #$20
    .i16
    ldy #$0000
    .a8
    lda #$09
    sta $01
release_nine_native_title_particle_sprite_records_97f9:
    phy
    ldx $0C,Y
    jsr routine_7eb786
    ply
    iny
    iny
    dec $01
    bne release_nine_native_title_particle_sprite_records_97f9
    plp
    rts
