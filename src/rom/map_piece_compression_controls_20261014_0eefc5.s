.setcpu "65816"
.segment "CODE"
.org $EFC5
map_control_0eefc5:
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
