.setcpu "65816"
.segment "CODE"
.org $A94D
map_control_0fa94d:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
