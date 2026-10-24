.setcpu "65816"
.segment "CODE"
.org $F881
map_control_0ef881:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
