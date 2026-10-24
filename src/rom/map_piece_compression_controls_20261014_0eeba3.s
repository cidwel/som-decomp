.setcpu "65816"
.segment "CODE"
.org $EBA3
map_control_0eeba3:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
