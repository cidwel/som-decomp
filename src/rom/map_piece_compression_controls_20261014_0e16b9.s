.setcpu "65816"
.segment "CODE"
.org $16B9
map_control_0e16b9:
    .byte $E8 ; backreference distance high bits
    .byte $13 ; distance low bit/count
    .byte $E7 ; previous-row copy count
