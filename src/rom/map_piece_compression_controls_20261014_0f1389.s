.setcpu "65816"
.segment "CODE"
.org $1389
map_control_0f1389:
    .byte $E0 ; previous-row copy escape
    .byte $24 ; row-distance/count
