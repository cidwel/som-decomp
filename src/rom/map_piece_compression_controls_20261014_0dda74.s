.setcpu "65816"
.segment "CODE"
.org $DA74
map_control_0dda74:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $46 ; row-distance/count
