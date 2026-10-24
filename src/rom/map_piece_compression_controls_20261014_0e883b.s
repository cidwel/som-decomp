.setcpu "65816"
.segment "CODE"
.org $883B
map_control_0e883b:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $87 ; row-distance/count
