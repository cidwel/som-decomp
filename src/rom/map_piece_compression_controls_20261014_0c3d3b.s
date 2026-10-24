.setcpu "65816"
.segment "CODE"
.org $3D3B
map_control_0c3d3b:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
