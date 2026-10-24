.setcpu "65816"
.segment "CODE"
.org $ACC3
map_control_0facc3:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
