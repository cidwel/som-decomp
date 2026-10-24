.setcpu "65816"
.segment "CODE"
.org $20C9
map_control_0e20c9:
    .byte $E1 ; previous-row copy count
    .byte $E9 ; backreference distance high bits
    .byte $06 ; distance low bit/count
