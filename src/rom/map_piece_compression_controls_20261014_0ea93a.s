.setcpu "65816"
.segment "CODE"
.org $A93A
map_control_0ea93a:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
