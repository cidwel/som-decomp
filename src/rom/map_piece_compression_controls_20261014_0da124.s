.setcpu "65816"
.segment "CODE"
.org $A124
map_control_0da124:
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
