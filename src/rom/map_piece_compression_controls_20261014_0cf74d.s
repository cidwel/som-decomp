.setcpu "65816"
.segment "CODE"
.org $F74D
map_control_0cf74d:
    .byte $E4 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
