.setcpu "65816"
.segment "CODE"
.org $24D0
map_control_0c24d0:
    .byte $E0 ; previous-row copy escape
    .byte $26 ; row-distance/count
