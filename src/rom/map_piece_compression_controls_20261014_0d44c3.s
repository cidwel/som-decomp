.setcpu "65816"
.segment "CODE"
.org $44C3
map_control_0d44c3:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E7 ; previous-row copy count
