.setcpu "65816"
.segment "CODE"
.org $8577
map_control_0e8577:
    .byte $E0 ; previous-row copy escape
    .byte $A1 ; row-distance/count
