.setcpu "65816"
.segment "CODE"
.org $A521
map_control_0fa521:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
