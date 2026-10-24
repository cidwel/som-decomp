.setcpu "65816"
.segment "CODE"
.org $A8DD
map_control_0ea8dd:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
