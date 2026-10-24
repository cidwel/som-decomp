.setcpu "65816"
.segment "CODE"
.org $5E3D
map_control_0f5e3d:
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
