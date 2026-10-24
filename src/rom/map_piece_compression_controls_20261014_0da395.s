.setcpu "65816"
.segment "CODE"
.org $A395
map_control_0da395:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
