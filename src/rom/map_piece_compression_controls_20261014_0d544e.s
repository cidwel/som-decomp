.setcpu "65816"
.segment "CODE"
.org $544E
map_control_0d544e:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
