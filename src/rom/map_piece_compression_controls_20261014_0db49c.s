.setcpu "65816"
.segment "CODE"
.org $B49C
map_control_0db49c:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E7 ; previous-row copy count
