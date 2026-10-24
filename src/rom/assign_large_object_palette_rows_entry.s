; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

assign_large_object_palette_rows = $E2A8

.segment "CODE"
.org $E1A2
assign_large_object_palette_rows_entry:
    rep #$20
    jsr assign_large_object_palette_rows
    rtl
