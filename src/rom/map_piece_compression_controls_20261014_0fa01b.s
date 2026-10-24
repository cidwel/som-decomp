.setcpu "65816"
.segment "CODE"
.org $A01B
map_control_0fa01b:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
