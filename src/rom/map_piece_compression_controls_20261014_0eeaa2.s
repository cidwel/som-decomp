.setcpu "65816"
.segment "CODE"
.org $EAA2
map_control_0eeaa2:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
