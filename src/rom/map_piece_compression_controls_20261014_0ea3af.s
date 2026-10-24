.setcpu "65816"
.segment "CODE"
.org $A3AF
map_control_0ea3af:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
