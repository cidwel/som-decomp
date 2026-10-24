.setcpu "65816"
.segment "CODE"
.org $2435
map_control_0c2435:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
