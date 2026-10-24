.setcpu "65816"
.segment "CODE"
.org $AE19
map_control_0fae19:
    .byte $E0 ; previous-row copy escape
    .byte $A1 ; row-distance/count
