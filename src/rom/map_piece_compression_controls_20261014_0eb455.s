.setcpu "65816"
.segment "CODE"
.org $B455
map_control_0eb455:
    .byte $E0 ; previous-row copy escape
    .byte $8F ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
