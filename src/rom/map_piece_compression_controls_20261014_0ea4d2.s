.setcpu "65816"
.segment "CODE"
.org $A4D2
map_control_0ea4d2:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
