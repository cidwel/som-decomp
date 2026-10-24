.setcpu "65816"
.segment "CODE"
.org $E688
map_control_0de688:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E1 ; previous-row copy count
