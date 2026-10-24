.setcpu "65816"
.segment "CODE"
.org $1FB0
map_control_0e1fb0:
    .byte $E9 ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E4 ; previous-row copy count
