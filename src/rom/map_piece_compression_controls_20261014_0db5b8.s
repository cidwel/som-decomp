.setcpu "65816"
.segment "CODE"
.org $B5B8
map_control_0db5b8:
    .byte $E8 ; backreference distance high bits
    .byte $16 ; distance low bit/count
    .byte $E6 ; previous-row copy count
