.setcpu "65816"
.segment "CODE"
.org $3D7D
map_control_0c3d7d:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
