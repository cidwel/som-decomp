.setcpu "65816"
.segment "CODE"
.org $F973
map_control_0ff973:
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
