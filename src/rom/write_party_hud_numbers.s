; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

write_actor_hud_hp = $E369

.segment "CODE"
.org $E339
write_party_hud_numbers:
    sep #$20
    lda f:$7ECF00
    bne write_party_hud_numbers_c1e342
    rts
write_party_hud_numbers_c1e342:
    rep #$10
    stz a:$2115
    lda a:$0A55
    beq write_party_hud_numbers_c1e352
    .i16
    ldx #$0000
    jsr write_actor_hud_hp
write_party_hud_numbers_c1e352:
    lda a:$0A65
    beq write_party_hud_numbers_c1e35d
    .i16
    ldx #$0200
    jsr write_actor_hud_hp
write_party_hud_numbers_c1e35d:
    lda a:$0A75
    beq write_party_hud_numbers_c1e368
    .i16
    ldx #$0400
    jsr write_actor_hud_hp
write_party_hud_numbers_c1e368:
    rts
