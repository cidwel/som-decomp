.setcpu "65816"
.segment "CODE"
.org $A38D
map_control_0da38d:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
