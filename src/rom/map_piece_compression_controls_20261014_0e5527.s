.setcpu "65816"
.segment "CODE"
.org $5527
map_control_0e5527:
    .byte $E0 ; previous-row copy escape
    .byte $2A ; row-distance/count
