.setcpu "65816"
.segment "CODE"
.org $C442
map_control_0ec442:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
