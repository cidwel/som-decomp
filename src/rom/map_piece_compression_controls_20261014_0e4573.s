.setcpu "65816"
.segment "CODE"
.org $4573
map_control_0e4573:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
