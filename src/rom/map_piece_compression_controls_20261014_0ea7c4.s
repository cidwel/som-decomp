.setcpu "65816"
.segment "CODE"
.org $A7C4
map_control_0ea7c4:
    .byte $E0 ; previous-row copy escape
    .byte $2E ; row-distance/count
