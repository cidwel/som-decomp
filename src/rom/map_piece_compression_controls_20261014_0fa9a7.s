.setcpu "65816"
.segment "CODE"
.org $A9A7
map_control_0fa9a7:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
