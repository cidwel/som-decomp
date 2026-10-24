.setcpu "65816"
.segment "CODE"
.org $428D
map_control_0f428d:
    .byte $E0 ; previous-row copy escape
    .byte $26 ; row-distance/count
