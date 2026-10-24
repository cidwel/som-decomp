.setcpu "65816"
.segment "CODE"
.org $134F
map_control_0d134f:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
