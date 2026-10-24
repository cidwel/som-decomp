.setcpu "65816"
.segment "CODE"
.org $3D38
map_control_0d3d38:
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
