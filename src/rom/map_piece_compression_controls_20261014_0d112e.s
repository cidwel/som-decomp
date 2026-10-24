.setcpu "65816"
.segment "CODE"
.org $112E
map_control_0d112e:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
