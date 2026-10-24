.setcpu "65816"
.segment "CODE"
.org $3AD0
map_control_0c3ad0:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
