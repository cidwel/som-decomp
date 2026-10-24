.setcpu "65816"
.segment "CODE"
.org $5531
map_control_0e5531:
    .byte $E0 ; previous-row copy escape
    .byte $29 ; row-distance/count
