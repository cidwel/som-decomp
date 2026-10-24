.setcpu "65816"
.segment "CODE"
.org $BBE0
map_control_0dbbe0:
    .byte $E0 ; previous-row copy escape
    .byte $3D ; row-distance/count
