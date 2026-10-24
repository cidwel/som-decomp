; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-twelve.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $556D
choose_descriptor_twelve_fixed_hurt_pointer:
    .a16
    lda #$DB08
    rts
