; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

copy_object_weapon_palette = $859B

.segment "CODE"
.org $85D8
load_object_weapon_palette_from_field_04f:
    rep #$10
    sep #$20
    ldx $14
    lda a:$E04F,X
    jmp copy_object_weapon_palette
