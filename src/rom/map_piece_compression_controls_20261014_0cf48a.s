.setcpu "65816"
.segment "CODE"
.org $F48A
map_control_0cf48a:
    .byte $E8 ; backreference distance high bits
    .byte $14 ; distance low bit/count
    .byte $E1 ; previous-row copy count
