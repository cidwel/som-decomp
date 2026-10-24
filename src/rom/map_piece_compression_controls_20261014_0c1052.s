.setcpu "65816"
.segment "CODE"
.org $1052
map_control_0c1052:
    .byte $E0 ; previous-row copy escape
    .byte $93 ; row-distance/count
