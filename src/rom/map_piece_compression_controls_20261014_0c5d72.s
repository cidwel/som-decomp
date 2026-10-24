.setcpu "65816"
.segment "CODE"
.org $5D72
map_control_0c5d72:
    .byte $E8 ; backreference distance high bits
    .byte $34 ; distance low bit/count
    .byte $E2 ; previous-row copy count
