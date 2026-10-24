.setcpu "65816"
.segment "CODE"
.org $B238
map_control_0fb238:
    .byte $E9 ; backreference distance high bits
    .byte $07 ; distance low bit/count
    .byte $E6 ; previous-row copy count
