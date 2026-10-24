.setcpu "65816"
.segment "CODE"
.org $BF1F
map_control_0ebf1f:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E7 ; previous-row copy count
