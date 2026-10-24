.setcpu "65816"
.segment "CODE"
.org $8A01
map_control_0d8a01:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
