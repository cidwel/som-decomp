.setcpu "65816"
.segment "CODE"
.org $00FA
map_control_0f00fa:
    .byte $E0 ; previous-row copy escape
    .byte $8C ; row-distance/count
