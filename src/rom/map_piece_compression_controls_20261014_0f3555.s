.setcpu "65816"
.segment "CODE"
.org $3555
map_control_0f3555:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $3D ; row-distance/count
