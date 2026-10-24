.setcpu "65816"
.segment "CODE"
.org $CA2E
map_control_0fca2e:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
