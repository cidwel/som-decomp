.setcpu "65816"
.segment "CODE"
.org $5FC0
map_control_0e5fc0:
    .byte $E0 ; previous-row copy escape
    .byte $3D ; row-distance/count
