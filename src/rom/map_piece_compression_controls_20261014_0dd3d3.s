.setcpu "65816"
.segment "CODE"
.org $D3D3
map_control_0dd3d3:
    .byte $E0 ; previous-row copy escape
    .byte $29 ; row-distance/count
