.setcpu "65816"
.segment "CODE"
.org $A13B
map_control_0fa13b:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
