.setcpu "65816"
.segment "CODE"
.org $A0B2
map_control_0ea0b2:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
