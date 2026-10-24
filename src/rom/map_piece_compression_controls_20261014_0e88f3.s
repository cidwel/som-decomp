.setcpu "65816"
.segment "CODE"
.org $88F3
map_control_0e88f3:
    .byte $E0 ; previous-row copy escape
    .byte $A8 ; row-distance/count
