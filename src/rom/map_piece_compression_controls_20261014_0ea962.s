.setcpu "65816"
.segment "CODE"
.org $A962
map_control_0ea962:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
