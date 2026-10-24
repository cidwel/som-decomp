.setcpu "65816"
.segment "CODE"
.org $3D4B
map_control_0c3d4b:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
