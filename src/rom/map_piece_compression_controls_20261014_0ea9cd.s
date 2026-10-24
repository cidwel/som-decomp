.setcpu "65816"
.segment "CODE"
.org $A9CD
map_control_0ea9cd:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
