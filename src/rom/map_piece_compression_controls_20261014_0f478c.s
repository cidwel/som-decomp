.setcpu "65816"
.segment "CODE"
.org $478C
map_control_0f478c:
    .byte $E0 ; previous-row copy escape
    .byte $56 ; row-distance/count
