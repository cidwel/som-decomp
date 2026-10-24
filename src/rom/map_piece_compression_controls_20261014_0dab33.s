.setcpu "65816"
.segment "CODE"
.org $AB33
map_control_0dab33:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $8E ; row-distance/count
