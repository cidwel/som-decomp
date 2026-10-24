.setcpu "65816"
.segment "CODE"
.org $A5AE
map_control_0ea5ae:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
