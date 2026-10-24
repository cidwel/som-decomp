.setcpu "65816"
.segment "CODE"
.org $A578
map_control_0ea578:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
