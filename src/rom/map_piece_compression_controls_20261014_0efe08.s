.setcpu "65816"
.segment "CODE"
.org $FE08
map_control_0efe08:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
