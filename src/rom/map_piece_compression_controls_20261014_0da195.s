.setcpu "65816"
.segment "CODE"
.org $A195
map_control_0da195:
    .byte $E0 ; previous-row copy escape
    .byte $8B ; row-distance/count
