.setcpu "65816"
.segment "CODE"
.org $A3B9
map_control_0ea3b9:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
