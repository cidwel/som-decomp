.setcpu "65816"
.segment "CODE"
.org $7B3D
map_control_0d7b3d:
    .byte $E0 ; previous-row copy escape
    .byte $8D ; row-distance/count
