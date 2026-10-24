.setcpu "65816"
.segment "CODE"
.org $21A2
map_control_0d21a2:
    .byte $E0 ; previous-row copy escape
    .byte $A2 ; row-distance/count
