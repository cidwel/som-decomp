.setcpu "65816"
.segment "CODE"
.org $F0D8
map_control_0ef0d8:
    .byte $E2 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
