.setcpu "65816"
.segment "CODE"
.org $A98C
map_control_0fa98c:
    .byte $E0 ; previous-row copy escape
    .byte $C7 ; row-distance/count
