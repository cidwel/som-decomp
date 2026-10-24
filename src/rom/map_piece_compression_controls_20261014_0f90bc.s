.setcpu "65816"
.segment "CODE"
.org $90BC
map_control_0f90bc:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
