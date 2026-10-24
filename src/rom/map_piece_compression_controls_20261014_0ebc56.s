.setcpu "65816"
.segment "CODE"
.org $BC56
map_control_0ebc56:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $F2 ; row-distance/count
