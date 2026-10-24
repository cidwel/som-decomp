.setcpu "65816"
.segment "CODE"
.org $A06F
map_control_0fa06f:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
