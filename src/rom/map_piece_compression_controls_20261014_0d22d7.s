.setcpu "65816"
.segment "CODE"
.org $22D7
map_control_0d22d7:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
