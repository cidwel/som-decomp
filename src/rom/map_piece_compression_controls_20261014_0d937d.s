.setcpu "65816"
.segment "CODE"
.org $937D
map_control_0d937d:
    .byte $E0 ; previous-row copy escape
    .byte $35 ; row-distance/count
