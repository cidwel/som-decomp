.setcpu "65816"
.segment "CODE"
.org $6AFD
map_control_0f6afd:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
