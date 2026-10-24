.setcpu "65816"
.segment "CODE"
.org $BF88
map_control_0ebf88:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E5 ; previous-row copy count
