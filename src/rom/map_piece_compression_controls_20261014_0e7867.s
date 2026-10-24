.setcpu "65816"
.segment "CODE"
.org $7867
map_control_0e7867:
    .byte $E0 ; previous-row copy escape
    .byte $A3 ; row-distance/count
