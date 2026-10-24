.setcpu "65816"
.segment "CODE"
.org $B91C
map_control_0db91c:
    .byte $E1 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $88 ; distance low bit/count
