.setcpu "65816"
.segment "CODE"
.org $8D73
map_control_0d8d73:
    .byte $E8 ; backreference distance high bits
    .byte $1A ; distance low bit/count
    .byte $E3 ; previous-row copy count
