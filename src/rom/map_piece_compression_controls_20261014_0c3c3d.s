.setcpu "65816"
.segment "CODE"
.org $3C3D
map_control_0c3c3d:
    .byte $E0 ; previous-row copy escape
    .byte $2B ; row-distance/count
