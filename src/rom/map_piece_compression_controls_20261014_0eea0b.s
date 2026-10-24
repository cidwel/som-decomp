.setcpu "65816"
.segment "CODE"
.org $EA0B
map_control_0eea0b:
    .byte $EF ; backreference distance high bits
    .byte $8E ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
