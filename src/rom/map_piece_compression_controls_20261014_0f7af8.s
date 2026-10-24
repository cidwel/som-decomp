.setcpu "65816"
.segment "CODE"
.org $7AF8
map_control_0f7af8:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
