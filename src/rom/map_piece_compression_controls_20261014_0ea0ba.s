.setcpu "65816"
.segment "CODE"
.org $A0BA
map_control_0ea0ba:
    .byte $E0 ; previous-row copy escape
    .byte $70 ; row-distance/count
