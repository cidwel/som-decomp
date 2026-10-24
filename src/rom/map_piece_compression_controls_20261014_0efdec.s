.setcpu "65816"
.segment "CODE"
.org $FDEC
map_control_0efdec:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
