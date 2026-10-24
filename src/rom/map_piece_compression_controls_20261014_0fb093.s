.setcpu "65816"
.segment "CODE"
.org $B093
map_control_0fb093:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
