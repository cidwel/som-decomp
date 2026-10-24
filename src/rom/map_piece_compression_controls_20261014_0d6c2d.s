.setcpu "65816"
.segment "CODE"
.org $6C2D
map_control_0d6c2d:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
