.setcpu "65816"
.segment "CODE"
.org $A63A
map_control_0da63a:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
