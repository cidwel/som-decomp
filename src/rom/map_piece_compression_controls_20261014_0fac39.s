.setcpu "65816"
.segment "CODE"
.org $AC39
map_control_0fac39:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
