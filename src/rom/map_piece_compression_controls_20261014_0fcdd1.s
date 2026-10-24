.setcpu "65816"
.segment "CODE"
.org $CDD1
map_control_0fcdd1:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
