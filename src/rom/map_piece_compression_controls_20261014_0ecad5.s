.setcpu "65816"
.segment "CODE"
.org $CAD5
map_control_0ecad5:
    .byte $E0 ; previous-row copy escape
    .byte $A5 ; row-distance/count
