.setcpu "65816"
.segment "CODE"
.org $F7E2
map_control_0cf7e2:
    .byte $E1 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $14 ; distance low bit/count
