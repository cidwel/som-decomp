.setcpu "65816"
.segment "CODE"
.org $6504
map_control_0e6504:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
