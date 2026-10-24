; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $C42C
restore_map_saved_palette_rows:
    phb
    .a8
    lda #$7E
    pha
    plb
    ldx a:$DE02
    stx a:$0602
    ldx a:$DE04
    stx a:$0604
    ldx a:$DE06
    stx a:$0606
    ldx a:$DE08
    stx a:$0608
    ldx a:$DE0A
    stx a:$060A
    ldx a:$DE0C
    stx a:$060C
    ldx a:$DE0E
    stx a:$060E
    plb
    rts
