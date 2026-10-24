.setcpu "65816"
.segment "CODE"
.org $A9B9
map_control_0fa9b9:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
