.setcpu "65816"
.segment "CODE"
.org $A605
map_control_0da605:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
