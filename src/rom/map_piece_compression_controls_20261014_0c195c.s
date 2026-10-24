.setcpu "65816"
.segment "CODE"
.org $195C
map_control_0c195c:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
