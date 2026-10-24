.setcpu "65816"
.segment "CODE"
.org $AC68
map_control_0fac68:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
