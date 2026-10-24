.setcpu "65816"
.segment "CODE"
.org $F524
map_control_0cf524:
    .byte $E8 ; backreference distance high bits
    .byte $14 ; distance low bit/count
    .byte $E4 ; previous-row copy count
