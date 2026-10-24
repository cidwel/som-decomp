.setcpu "65816"
.segment "CODE"
.org $2387
map_control_0c2387:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
