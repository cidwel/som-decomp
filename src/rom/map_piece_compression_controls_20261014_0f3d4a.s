.setcpu "65816"
.segment "CODE"
.org $3D4A
map_control_0f3d4a:
    .byte $E0 ; previous-row copy escape
    .byte $24 ; row-distance/count
