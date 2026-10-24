.setcpu "65816"
.segment "CODE"
.org $F036
map_control_0ff036:
    .byte $E9 ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E4 ; previous-row copy count
