.setcpu "65816"
.segment "CODE"
.org $A6F5
map_control_0fa6f5:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
