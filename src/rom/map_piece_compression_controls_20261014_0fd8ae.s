.setcpu "65816"
.segment "CODE"
.org $D8AE
map_control_0fd8ae:
    .byte $E7 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
