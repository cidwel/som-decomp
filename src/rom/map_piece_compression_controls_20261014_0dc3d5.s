.setcpu "65816"
.segment "CODE"
.org $C3D5
map_control_0dc3d5:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
