.setcpu "65816"
.segment "CODE"
.org $3D0B
map_control_0f3d0b:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
