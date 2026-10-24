.setcpu "65816"
.segment "CODE"
.org $90D8
map_control_0e90d8:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
