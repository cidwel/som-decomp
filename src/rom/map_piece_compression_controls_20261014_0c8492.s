.setcpu "65816"
.segment "CODE"
.org $8492
map_control_0c8492:
    .byte $E0 ; previous-row copy escape
    .byte $35 ; row-distance/count
