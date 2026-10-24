.setcpu "65816"
.segment "CODE"
.org $F849
map_control_0ef849:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E1 ; previous-row copy count
