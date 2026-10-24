.setcpu "65816"
.segment "CODE"
.org $4B3D
map_control_0c4b3d:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
