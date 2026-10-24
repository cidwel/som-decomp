.setcpu "65816"
.segment "CODE"
.org $F908
map_control_0ef908:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
