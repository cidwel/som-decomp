.setcpu "65816"
.segment "CODE"
.org $8323
map_control_0e8323:
    .byte $E0 ; previous-row copy escape
    .byte $8C ; row-distance/count
