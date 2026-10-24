; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


palette_color_one = $0602
palette_color_two = $0604
palette_color_three = $0606
palette_color_four = $0608
palette_color_five = $060A
palette_color_six = $060C
palette_color_seven = $060E
snapshot_color_one = $DE02
snapshot_color_two = $DE04
snapshot_color_three = $DE06
snapshot_color_four = $DE08
snapshot_color_five = $DE0A
snapshot_color_six = $DE0C
snapshot_color_seven = $DE0E

.segment "CODE"
.org $F2AC
copy_map_palette_snapshot_and_hdma_records:
    rep #$20
    lda a:palette_color_one
    sta a:snapshot_color_one
    lda a:palette_color_two
    sta a:snapshot_color_two
    lda a:palette_color_three
    sta a:snapshot_color_three
    lda a:palette_color_four
    sta a:snapshot_color_four
    lda a:palette_color_five
    sta a:snapshot_color_five
    lda a:palette_color_six
    sta a:snapshot_color_six
    lda a:palette_color_seven
    sta a:snapshot_color_seven
    phb
    rep #$30
    .i16
    ldx #$F3C9
    .i16
    ldy #$05D0
    .a16
    lda #$0027
    mvn #$01, #$7E
    plb
    rts
