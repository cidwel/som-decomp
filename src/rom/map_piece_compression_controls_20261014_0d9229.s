.setcpu "65816"
.segment "CODE"
.org $9229
map_control_0d9229:
    .byte $E0 ; previous-row copy escape
    .byte $BC ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
