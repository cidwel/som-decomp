.setcpu "65816"
.segment "CODE"
.org $3D5F
map_control_0c3d5f:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
