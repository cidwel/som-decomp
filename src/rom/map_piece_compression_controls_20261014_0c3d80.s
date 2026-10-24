.setcpu "65816"
.segment "CODE"
.org $3D80
map_control_0c3d80:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
