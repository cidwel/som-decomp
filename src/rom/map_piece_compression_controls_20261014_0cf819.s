.setcpu "65816"
.segment "CODE"
.org $F819
map_control_0cf819:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
