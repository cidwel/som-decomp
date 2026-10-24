.setcpu "65816"
.segment "CODE"
.org $3D81
map_control_0e3d81:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
