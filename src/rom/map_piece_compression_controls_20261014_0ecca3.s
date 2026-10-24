.setcpu "65816"
.segment "CODE"
.org $CCA3
map_control_0ecca3:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
