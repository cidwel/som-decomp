.setcpu "65816"
.segment "CODE"
.org $C244
map_control_0ec244:
    .byte $E0 ; previous-row copy escape
    .byte $94 ; row-distance/count
