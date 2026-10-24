.setcpu "65816"
.segment "CODE"
.org $96D8
map_control_0f96d8:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $8F ; row-distance/count
