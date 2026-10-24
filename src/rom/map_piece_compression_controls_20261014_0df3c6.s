.setcpu "65816"
.segment "CODE"
.org $F3C6
map_control_0df3c6:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E1 ; previous-row copy count
