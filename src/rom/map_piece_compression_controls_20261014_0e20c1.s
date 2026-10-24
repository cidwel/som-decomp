.setcpu "65816"
.segment "CODE"
.org $20C1
map_control_0e20c1:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
