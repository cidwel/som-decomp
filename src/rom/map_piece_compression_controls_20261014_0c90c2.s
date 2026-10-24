.setcpu "65816"
.segment "CODE"
.org $90C2
map_control_0c90c2:
    .byte $E0 ; previous-row copy escape
    .byte $A3 ; row-distance/count
