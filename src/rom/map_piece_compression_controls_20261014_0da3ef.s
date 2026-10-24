.setcpu "65816"
.segment "CODE"
.org $A3EF
map_control_0da3ef:
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
