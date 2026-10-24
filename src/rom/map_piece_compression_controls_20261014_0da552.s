.setcpu "65816"
.segment "CODE"
.org $A552
map_control_0da552:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
