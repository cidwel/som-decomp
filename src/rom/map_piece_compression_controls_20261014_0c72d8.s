.setcpu "65816"
.segment "CODE"
.org $72D8
map_control_0c72d8:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
