; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

copy_object_weapon_palette = $859B

.segment "CODE"
.org $85E4
load_object_weapon_palette_from_field_069:
    rep #$10
    sep #$20
    ldx $14
    lda a:$E069,X
    jsr copy_object_weapon_palette
    rtl
