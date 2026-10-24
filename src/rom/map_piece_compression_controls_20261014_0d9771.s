.setcpu "65816"
.segment "CODE"
.org $9771
map_control_0d9771:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
