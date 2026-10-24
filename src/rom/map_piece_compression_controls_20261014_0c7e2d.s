.setcpu "65816"
.segment "CODE"
.org $7E2D
map_control_0c7e2d:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
