.setcpu "65816"
.segment "CODE"
.org $666A
map_control_0d666a:
    .byte $E0 ; previous-row copy escape
    .byte $22 ; row-distance/count
