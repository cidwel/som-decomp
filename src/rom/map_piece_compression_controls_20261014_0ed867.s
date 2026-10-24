.setcpu "65816"
.segment "CODE"
.org $D867
map_control_0ed867:
    .byte $E0 ; previous-row copy escape
    .byte $90 ; row-distance/count
