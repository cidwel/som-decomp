.setcpu "65816"
.segment "CODE"
.org $701E
map_control_0e701e:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
