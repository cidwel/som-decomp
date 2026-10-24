.setcpu "65816"
.segment "CODE"
.org $A890
map_control_0ea890:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
