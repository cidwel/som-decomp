.setcpu "65816"
.segment "CODE"
.org $BC5F
map_control_0fbc5f:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
