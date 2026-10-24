.setcpu "65816"
.segment "CODE"
.org $112E
map_control_0c112e:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
