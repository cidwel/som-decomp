.setcpu "65816"
.segment "CODE"
.org $3E0D
map_control_0f3e0d:
    .byte $E0 ; previous-row copy escape
    .byte $3D ; row-distance/count
