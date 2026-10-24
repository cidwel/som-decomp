; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

convert_object_graphics_planes_inverted = $C8A9
convert_object_graphics_planes_masked = $C5D1
convert_object_graphics_planes_xor = $C731

.segment "CODE"
.org $C599
dispatch_object_graphics_plane_conversion:
    sep #$20
    phb
    pha
    plb
    rep #$10
    stx $02
    lda $03
    lsr
    sta $04
    asl
    asl
    asl
    asl
    ora $01
    sta $01
    stz $00
    ldx $00
    lda $04
    .a8
    cmp #$03
    bcc dispatch_object_graphics_plane_conversion_c1c5bb
    .a8
    sbc #$03
dispatch_object_graphics_plane_conversion_c1c5bb:
    .a8
    cmp #$00
    beq dispatch_object_graphics_plane_conversion_c1c5cc
    dec
    beq dispatch_object_graphics_plane_conversion_c1c5c7
    jsr convert_object_graphics_planes_inverted
    plb
    rtl
dispatch_object_graphics_plane_conversion_c1c5c7:
    jsr convert_object_graphics_planes_xor
    plb
    rtl
dispatch_object_graphics_plane_conversion_c1c5cc:
    jsr convert_object_graphics_planes_masked
    plb
    rtl
