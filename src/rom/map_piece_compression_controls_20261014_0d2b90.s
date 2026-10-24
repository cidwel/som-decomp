.setcpu "65816"
.segment "CODE"
.org $2B90
map_control_0d2b90:
    .byte $E0 ; previous-row copy escape
    .byte $92 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $2A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $3F ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $68 ; row-distance/count
