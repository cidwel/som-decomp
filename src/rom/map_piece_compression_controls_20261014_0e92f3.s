.setcpu "65816"
.segment "CODE"
.org $92F3
map_control_0e92f3:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
