.setcpu "65816"
.segment "CODE"
.org $BB0F
map_control_0fbb0f:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
