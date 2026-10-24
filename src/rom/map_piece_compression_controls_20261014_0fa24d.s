.setcpu "65816"
.segment "CODE"
.org $A24D
map_control_0fa24d:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
