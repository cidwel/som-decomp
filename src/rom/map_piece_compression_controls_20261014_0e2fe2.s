.setcpu "65816"
.segment "CODE"
.org $2FE2
map_control_0e2fe2:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
