.setcpu "65816"
.segment "CODE"
.org $3D39
map_control_0f3d39:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
