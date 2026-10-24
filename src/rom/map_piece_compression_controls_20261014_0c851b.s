.setcpu "65816"
.segment "CODE"
.org $851B
map_control_0c851b:
    .byte $E0 ; previous-row copy escape
    .byte $35 ; row-distance/count
