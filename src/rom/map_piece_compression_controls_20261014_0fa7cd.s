.setcpu "65816"
.segment "CODE"
.org $A7CD
map_control_0fa7cd:
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
