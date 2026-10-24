.setcpu "65816"
.segment "CODE"
.org $7D3D
map_control_0d7d3d:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
