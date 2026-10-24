.setcpu "65816"
.segment "CODE"
.org $4032
map_control_0e4032:
    .byte $E7 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
