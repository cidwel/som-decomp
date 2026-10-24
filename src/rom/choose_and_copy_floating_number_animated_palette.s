; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $8564
choose_and_copy_floating_number_animated_palette:
    sep #$20
    lda a:$E11F,X
    beq choose_and_copy_floating_number_animated_palette_c1857c
    .a8
    cmp #$E0
    bcs choose_and_copy_floating_number_animated_palette_c18592
    lsr
    lsr
    lsr
    lsr
    lsr
    .a8
    eor #$07
    .a8
    cmp #$03
    bcs choose_and_copy_floating_number_animated_palette_c18598
    bcc choose_and_copy_floating_number_animated_palette_c18592
choose_and_copy_floating_number_animated_palette_c1857c:
    lda a:$E11C,X
    .a8
    cmp #$08
    bne choose_and_copy_floating_number_animated_palette_c18592
    lda a:$E11E,X
    .a8
    cmp #$80
    bcs choose_and_copy_floating_number_animated_palette_c18596
    .a8
    cmp #$30
    bcs choose_and_copy_floating_number_animated_palette_c18592
    .a8
    lda #$00
    bra choose_and_copy_floating_number_animated_palette_c18598
choose_and_copy_floating_number_animated_palette_c18592:
    .a8
    lda #$01
    bra choose_and_copy_floating_number_animated_palette_c18598
choose_and_copy_floating_number_animated_palette_c18596:
    .a8
    lda #$02
choose_and_copy_floating_number_animated_palette_c18598:
    ora a:$E04F,X
