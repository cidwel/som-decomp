.setcpu "65816"
.segment "CODE"
.org $A5A0
map_control_0fa5a0:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
