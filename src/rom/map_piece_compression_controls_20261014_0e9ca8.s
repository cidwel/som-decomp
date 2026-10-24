.setcpu "65816"
.segment "CODE"
.org $9CA8
map_control_0e9ca8:
    .byte $E8 ; backreference distance high bits
    .byte $1A ; distance low bit/count
    .byte $E3 ; previous-row copy count
