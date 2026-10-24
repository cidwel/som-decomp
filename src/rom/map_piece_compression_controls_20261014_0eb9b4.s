.setcpu "65816"
.segment "CODE"
.org $B9B4
map_control_0eb9b4:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E4 ; previous-row copy count
