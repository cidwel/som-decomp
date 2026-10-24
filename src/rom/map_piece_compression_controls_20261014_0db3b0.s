.setcpu "65816"
.segment "CODE"
.org $B3B0
map_control_0db3b0:
    .byte $E1 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
