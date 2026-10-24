.setcpu "65816"
.segment "CODE"
.org $5D3D
map_control_0f5d3d:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
    .byte $C5 ; same-value copy count/distance
