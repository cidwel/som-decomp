.setcpu "65816"
.segment "CODE"
.org $A864
map_control_0ea864:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
