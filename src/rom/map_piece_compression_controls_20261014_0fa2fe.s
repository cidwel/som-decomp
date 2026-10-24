.setcpu "65816"
.segment "CODE"
.org $A2FE
map_control_0fa2fe:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
