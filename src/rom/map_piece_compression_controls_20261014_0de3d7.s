.setcpu "65816"
.segment "CODE"
.org $E3D7
map_control_0de3d7:
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
