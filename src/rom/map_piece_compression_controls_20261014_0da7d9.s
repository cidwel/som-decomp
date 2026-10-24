.setcpu "65816"
.segment "CODE"
.org $A7D9
map_control_0da7d9:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E1 ; previous-row copy count
