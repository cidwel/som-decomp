.setcpu "65816"
.segment "CODE"
.org $A107
map_control_0da107:
    .byte $E0 ; previous-row copy escape
    .byte $8D ; row-distance/count
