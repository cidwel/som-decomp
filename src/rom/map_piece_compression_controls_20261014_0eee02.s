.setcpu "65816"
.segment "CODE"
.org $EE02
map_control_0eee02:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
