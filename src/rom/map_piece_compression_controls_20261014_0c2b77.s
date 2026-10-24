.setcpu "65816"
.segment "CODE"
.org $2B77
map_control_0c2b77:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
