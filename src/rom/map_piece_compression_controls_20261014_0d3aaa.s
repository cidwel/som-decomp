.setcpu "65816"
.segment "CODE"
.org $3AAA
map_control_0d3aaa:
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E1 ; previous-row copy count
