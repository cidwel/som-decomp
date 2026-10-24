.setcpu "65816"
.segment "CODE"
.org $90E2
map_control_0d90e2:
    .byte $E0 ; previous-row copy escape
    .byte $A4 ; row-distance/count
