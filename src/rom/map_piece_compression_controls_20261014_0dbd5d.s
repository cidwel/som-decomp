.setcpu "65816"
.segment "CODE"
.org $BD5D
map_control_0dbd5d:
    .byte $E0 ; previous-row copy escape
    .byte $3D ; row-distance/count
