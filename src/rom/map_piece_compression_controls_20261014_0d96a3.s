.setcpu "65816"
.segment "CODE"
.org $96A3
map_control_0d96a3:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
