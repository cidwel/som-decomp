.setcpu "65816"
.segment "CODE"
.org $B0D8
map_control_0fb0d8:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
