.setcpu "65816"
.segment "CODE"
.org $7548
map_control_0f7548:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
