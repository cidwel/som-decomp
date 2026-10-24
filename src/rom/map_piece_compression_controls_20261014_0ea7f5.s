.setcpu "65816"
.segment "CODE"
.org $A7F5
map_control_0ea7f5:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
