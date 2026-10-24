.setcpu "65816"
.segment "CODE"
.org $8D52
map_control_0f8d52:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
