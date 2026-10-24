.setcpu "65816"
.segment "CODE"
.org $2D88
map_control_0d2d88:
    .byte $E0 ; previous-row copy escape
    .byte $3D ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $26 ; row-distance/count
