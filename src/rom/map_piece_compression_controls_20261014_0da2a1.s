.setcpu "65816"
.segment "CODE"
.org $A2A1
map_control_0da2a1:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
