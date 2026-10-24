.setcpu "65816"
.segment "CODE"
.org $FDF9
map_control_0efdf9:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
