.setcpu "65816"
.segment "CODE"
.org $1460
map_control_0c1460:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
