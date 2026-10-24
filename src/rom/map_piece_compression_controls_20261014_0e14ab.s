.setcpu "65816"
.segment "CODE"
.org $14AB
map_control_0e14ab:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $69 ; row-distance/count
