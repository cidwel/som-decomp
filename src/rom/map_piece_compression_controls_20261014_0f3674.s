.setcpu "65816"
.segment "CODE"
.org $3674
map_control_0f3674:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
