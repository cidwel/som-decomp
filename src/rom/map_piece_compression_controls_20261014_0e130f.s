.setcpu "65816"
.segment "CODE"
.org $130F
map_control_0e130f:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
