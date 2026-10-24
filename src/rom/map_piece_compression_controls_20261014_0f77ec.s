.setcpu "65816"
.segment "CODE"
.org $77EC
map_control_0f77ec:
    .byte $E9 ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
