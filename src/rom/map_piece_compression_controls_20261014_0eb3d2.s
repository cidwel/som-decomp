.setcpu "65816"
.segment "CODE"
.org $B3D2
map_control_0eb3d2:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
