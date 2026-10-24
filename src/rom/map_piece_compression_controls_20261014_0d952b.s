.setcpu "65816"
.segment "CODE"
.org $952B
map_control_0d952b:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
