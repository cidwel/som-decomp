.setcpu "65816"
.segment "CODE"
.org $7D89
map_control_0c7d89:
    .byte $E1 ; previous-row copy count
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
