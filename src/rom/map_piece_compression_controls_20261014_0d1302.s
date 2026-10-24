.setcpu "65816"
.segment "CODE"
.org $1302
map_control_0d1302:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
    .byte $E1 ; previous-row copy count
