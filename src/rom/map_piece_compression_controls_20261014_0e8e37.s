.setcpu "65816"
.segment "CODE"
.org $8E37
map_control_0e8e37:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $5F ; row-distance/count
