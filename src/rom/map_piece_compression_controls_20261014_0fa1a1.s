.setcpu "65816"
.segment "CODE"
.org $A1A1
map_control_0fa1a1:
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
