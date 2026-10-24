.setcpu "65816"
.segment "CODE"
.org $AC46
map_control_0fac46:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
