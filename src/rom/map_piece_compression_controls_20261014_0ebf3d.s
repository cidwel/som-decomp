.setcpu "65816"
.segment "CODE"
.org $BF3D
map_control_0ebf3d:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
