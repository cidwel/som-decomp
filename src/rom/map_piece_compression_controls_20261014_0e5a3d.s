.setcpu "65816"
.segment "CODE"
.org $5A3D
map_control_0e5a3d:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
