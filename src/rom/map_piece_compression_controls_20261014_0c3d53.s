.setcpu "65816"
.segment "CODE"
.org $3D53
map_control_0c3d53:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
