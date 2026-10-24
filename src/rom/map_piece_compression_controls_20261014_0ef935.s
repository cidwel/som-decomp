.setcpu "65816"
.segment "CODE"
.org $F935
map_control_0ef935:
    .byte $E3 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
