.setcpu "65816"
.segment "CODE"
.org $7477
map_control_0e7477:
    .byte $E0 ; previous-row copy escape
    .byte $96 ; row-distance/count
