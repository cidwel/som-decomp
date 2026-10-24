.setcpu "65816"
.segment "CODE"
.org $F819
map_control_0ef819:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
