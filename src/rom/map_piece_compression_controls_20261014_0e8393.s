.setcpu "65816"
.segment "CODE"
.org $8393
map_control_0e8393:
    .byte $E0 ; previous-row copy escape
    .byte $A0 ; row-distance/count
