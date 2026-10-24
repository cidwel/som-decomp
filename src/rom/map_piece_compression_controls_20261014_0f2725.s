.setcpu "65816"
.segment "CODE"
.org $2725
map_control_0f2725:
    .byte $E0 ; previous-row copy escape
    .byte $8C ; row-distance/count
