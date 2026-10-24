.setcpu "65816"
.segment "CODE"
.org $1317
map_control_0c1317:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
