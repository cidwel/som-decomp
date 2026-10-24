.setcpu "65816"
.segment "CODE"
.org $A2E6
map_control_0fa2e6:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
