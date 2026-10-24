.setcpu "65816"
.segment "CODE"
.org $6D3D
map_control_0c6d3d:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $1C ; distance low bit/count
