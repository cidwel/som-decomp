.setcpu "65816"
.segment "CODE"
.org $D9DA
map_control_0dd9da:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
