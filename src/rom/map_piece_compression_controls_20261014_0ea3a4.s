.setcpu "65816"
.segment "CODE"
.org $A3A4
map_control_0ea3a4:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
