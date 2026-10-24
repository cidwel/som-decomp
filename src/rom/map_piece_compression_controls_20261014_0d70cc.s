.setcpu "65816"
.segment "CODE"
.org $70CC
map_control_0d70cc:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E3 ; previous-row copy count
