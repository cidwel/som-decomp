.setcpu "65816"
.segment "CODE"
.org $23B3
map_control_0f23b3:
    .byte $E3 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
