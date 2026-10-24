.setcpu "65816"
.segment "CODE"
.org $BA22
map_control_0fba22:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
