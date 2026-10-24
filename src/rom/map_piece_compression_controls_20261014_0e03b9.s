.setcpu "65816"
.segment "CODE"
.org $03B9
map_control_0e03b9:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
