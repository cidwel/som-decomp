; Three additional raster half-width profiles; the first 16-byte profile is existing source.
.setcpu "65816"
.segment "CODE"
.org $96F2
ui_raster_window_remaining_half_widths:
    .byte $01, $02, $02, $03, $03, $0E, $0C, $0A, $08, $05, $0A, $07, $04, $05, $03, $02
    .byte $01, $03, $05, $04, $05, $08, $05, $06, $08, $0A, $0B, $03, $03, $02, $02, $01
    .byte $01, $02, $02, $03, $03, $0B, $0A, $08, $06, $05, $08, $05, $04, $05, $03, $01
