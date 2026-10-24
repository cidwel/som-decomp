.setcpu "65816"
.segment "CODE"
.org $C409
map_control_0dc409:
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
