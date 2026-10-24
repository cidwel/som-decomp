.setcpu "65816"
.segment "CODE"
.org $2476
map_control_0e2476:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $3A ; row-distance/count
