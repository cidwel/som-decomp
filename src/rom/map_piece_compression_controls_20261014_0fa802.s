.setcpu "65816"
.segment "CODE"
.org $A802
map_control_0fa802:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
