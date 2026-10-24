.setcpu "65816"
.segment "CODE"
.org $A90C
map_control_0fa90c:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
