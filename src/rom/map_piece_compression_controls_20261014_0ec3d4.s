.setcpu "65816"
.segment "CODE"
.org $C3D4
map_control_0ec3d4:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $40 ; row-distance/count
