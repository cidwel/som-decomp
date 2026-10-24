.setcpu "65816"
.segment "CODE"
.org $F488
map_control_0ef488:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
