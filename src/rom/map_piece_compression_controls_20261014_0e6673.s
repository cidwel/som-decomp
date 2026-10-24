.setcpu "65816"
.segment "CODE"
.org $6673
map_control_0e6673:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
