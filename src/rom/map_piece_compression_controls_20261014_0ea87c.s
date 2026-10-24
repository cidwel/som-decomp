.setcpu "65816"
.segment "CODE"
.org $A87C
map_control_0ea87c:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
