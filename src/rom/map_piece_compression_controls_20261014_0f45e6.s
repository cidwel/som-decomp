.setcpu "65816"
.segment "CODE"
.org $45E6
map_control_0f45e6:
    .byte $E0 ; previous-row copy escape
    .byte $46 ; row-distance/count
