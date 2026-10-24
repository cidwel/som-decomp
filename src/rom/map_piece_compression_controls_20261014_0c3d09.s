.setcpu "65816"
.segment "CODE"
.org $3D09
map_control_0c3d09:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
