.setcpu "65816"
.segment "CODE"
.org $FA3D
map_control_0efa3d:
    .byte $E0 ; previous-row copy escape
    .byte $BB ; row-distance/count
