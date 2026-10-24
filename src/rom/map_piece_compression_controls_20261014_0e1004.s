.setcpu "65816"
.segment "CODE"
.org $1004
map_control_0e1004:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
