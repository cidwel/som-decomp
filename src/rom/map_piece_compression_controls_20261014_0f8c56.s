.setcpu "65816"
.segment "CODE"
.org $8C56
map_control_0f8c56:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
