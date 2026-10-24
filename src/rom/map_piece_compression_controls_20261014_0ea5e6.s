.setcpu "65816"
.segment "CODE"
.org $A5E6
map_control_0ea5e6:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
