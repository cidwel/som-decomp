.setcpu "65816"
.segment "CODE"
.org $37F6
map_control_0d37f6:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E7 ; previous-row copy count
