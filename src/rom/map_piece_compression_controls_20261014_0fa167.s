.setcpu "65816"
.segment "CODE"
.org $A167
map_control_0fa167:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
