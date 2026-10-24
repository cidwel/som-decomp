.setcpu "65816"
.segment "CODE"
.org $303E
map_control_0e303e:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E4 ; previous-row copy count
