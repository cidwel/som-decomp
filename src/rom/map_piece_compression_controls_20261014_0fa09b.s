.setcpu "65816"
.segment "CODE"
.org $A09B
map_control_0fa09b:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
