.setcpu "65816"
.segment "CODE"
.org $5537
map_control_0c5537:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E3 ; previous-row copy count
