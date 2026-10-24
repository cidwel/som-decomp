.setcpu "65816"
.segment "CODE"
.org $4B36
map_control_0e4b36:
    .byte $E0 ; previous-row copy escape
    .byte $A8 ; row-distance/count
