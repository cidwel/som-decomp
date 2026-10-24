.setcpu "65816"
.segment "CODE"
.org $2357
map_control_0c2357:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
