.setcpu "65816"
.segment "CODE"
.org $A9DA
map_control_0ea9da:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
