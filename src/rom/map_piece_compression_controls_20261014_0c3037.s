.setcpu "65816"
.segment "CODE"
.org $3037
map_control_0c3037:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
