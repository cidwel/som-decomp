.setcpu "65816"
.segment "CODE"
.org $42A4
map_control_0d42a4:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E3 ; previous-row copy count
