.setcpu "65816"
.segment "CODE"
.org $B0EB
map_control_0fb0eb:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
