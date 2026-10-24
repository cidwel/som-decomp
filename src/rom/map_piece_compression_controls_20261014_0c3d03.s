.setcpu "65816"
.segment "CODE"
.org $3D03
map_control_0c3d03:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
