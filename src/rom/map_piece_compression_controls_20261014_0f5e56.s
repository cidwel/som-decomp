.setcpu "65816"
.segment "CODE"
.org $5E56
map_control_0f5e56:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
