.setcpu "65816"
.segment "CODE"
.org $DE48
map_control_0ede48:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
