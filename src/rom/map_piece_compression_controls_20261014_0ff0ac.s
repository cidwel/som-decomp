.setcpu "65816"
.segment "CODE"
.org $F0AC
map_control_0ff0ac:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E1 ; previous-row copy count
