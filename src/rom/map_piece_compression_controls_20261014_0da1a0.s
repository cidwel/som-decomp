.setcpu "65816"
.segment "CODE"
.org $A1A0
map_control_0da1a0:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
