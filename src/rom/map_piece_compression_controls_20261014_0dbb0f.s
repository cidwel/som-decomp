.setcpu "65816"
.segment "CODE"
.org $BB0F
map_control_0dbb0f:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
