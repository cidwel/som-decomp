.setcpu "65816"
.segment "CODE"
.org $E06F
map_control_0fe06f:
    .byte $EA ; backreference distance high bits
    .byte $8F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
