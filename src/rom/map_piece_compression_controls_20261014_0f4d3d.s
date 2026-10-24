.setcpu "65816"
.segment "CODE"
.org $4D3D
map_control_0f4d3d:
    .byte $E9 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $C4 ; row-distance/count
