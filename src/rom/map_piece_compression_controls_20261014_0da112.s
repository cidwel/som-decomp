.setcpu "65816"
.segment "CODE"
.org $A112
map_control_0da112:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
