.setcpu "65816"
.segment "CODE"
.org $467F
map_control_0f467f:
    .byte $E0 ; previous-row copy escape
    .byte $B8 ; row-distance/count
