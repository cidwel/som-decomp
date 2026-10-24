.setcpu "65816"
.segment "CODE"
.org $596A
map_control_0e596a:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
