.setcpu "65816"
.segment "CODE"
.org $A8B9
map_control_0ea8b9:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
