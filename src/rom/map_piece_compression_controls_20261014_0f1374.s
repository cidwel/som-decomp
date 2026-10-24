.setcpu "65816"
.segment "CODE"
.org $1374
map_control_0f1374:
    .byte $E0 ; previous-row copy escape
    .byte $D9 ; row-distance/count
