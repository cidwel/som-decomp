.setcpu "65816"
.segment "CODE"
.org $F076
map_control_0ff076:
    .byte $E9 ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E4 ; previous-row copy count
