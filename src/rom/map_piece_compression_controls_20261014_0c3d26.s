.setcpu "65816"
.segment "CODE"
.org $3D26
map_control_0c3d26:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
