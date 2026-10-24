.setcpu "65816"
.segment "CODE"
.org $CAB7
map_control_0ecab7:
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
