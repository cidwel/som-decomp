.setcpu "65816"
.segment "CODE"
.org $A2AE
map_control_0da2ae:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
