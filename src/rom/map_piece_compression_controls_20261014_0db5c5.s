.setcpu "65816"
.segment "CODE"
.org $B5C5
map_control_0db5c5:
    .byte $E8 ; backreference distance high bits
    .byte $16 ; distance low bit/count
    .byte $E6 ; previous-row copy count
