; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

decode_diagonal_coefficient_block = $995C
scale_image_coefficients = $9AA4
transform_image_coefficients = $9AD4

.segment "CODE"
.org $9D0E
decode_scale_transform_image_block:
    txa
    ldx a:$0116
    jsr decode_diagonal_coefficient_block
    pha
    jsr scale_image_coefficients
    jsr transform_image_coefficients
    plx
    rts
