.setcpu "65816"
.segment "CODE"
.org $A5C2
map_control_0da5c2:
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
