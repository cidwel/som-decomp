.setcpu "65816"
.segment "CODE"
.org $3D9D
map_control_0e3d9d:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
