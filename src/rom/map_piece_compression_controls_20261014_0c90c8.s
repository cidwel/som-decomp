.setcpu "65816"
.segment "CODE"
.org $90C8
map_control_0c90c8:
    .byte $E0 ; previous-row copy escape
    .byte $A9 ; row-distance/count
