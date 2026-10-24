.setcpu "65816"
.segment "CODE"
.org $194A
map_control_0f194a:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
