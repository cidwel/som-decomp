.setcpu "65816"
.segment "CODE"
.org $5E3F
map_control_0c5e3f:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $38 ; row-distance/count
