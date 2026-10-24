.setcpu "65816"
.segment "CODE"
.org $97F9
map_control_0d97f9:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
