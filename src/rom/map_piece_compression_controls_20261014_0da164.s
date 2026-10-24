.setcpu "65816"
.segment "CODE"
.org $A164
map_control_0da164:
    .byte $E0 ; previous-row copy escape
    .byte $8B ; row-distance/count
