.setcpu "65816"
.segment "CODE"
.org $3D85
map_control_0e3d85:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
