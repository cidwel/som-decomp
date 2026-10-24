.setcpu "65816"
.segment "CODE"
.org $C35B
map_control_0ec35b:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
