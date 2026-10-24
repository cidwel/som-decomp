.setcpu "65816"
.segment "CODE"
.org $5B3B
map_control_0f5b3b:
    .byte $E0 ; previous-row copy escape
    .byte $A1 ; row-distance/count
