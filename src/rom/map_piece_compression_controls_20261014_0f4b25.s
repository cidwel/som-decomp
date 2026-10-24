.setcpu "65816"
.segment "CODE"
.org $4B25
map_control_0f4b25:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
