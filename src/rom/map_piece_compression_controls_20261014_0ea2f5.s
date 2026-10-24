.setcpu "65816"
.segment "CODE"
.org $A2F5
map_control_0ea2f5:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
