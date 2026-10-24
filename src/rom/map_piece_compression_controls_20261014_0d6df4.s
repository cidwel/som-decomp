.setcpu "65816"
.segment "CODE"
.org $6DF4
map_control_0d6df4:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
