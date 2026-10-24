.setcpu "65816"
.segment "CODE"
.org $8CE6
map_control_0f8ce6:
    .byte $E0 ; previous-row copy escape
    .byte $38 ; row-distance/count
