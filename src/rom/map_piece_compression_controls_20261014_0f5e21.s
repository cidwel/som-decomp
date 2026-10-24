.setcpu "65816"
.segment "CODE"
.org $5E21
map_control_0f5e21:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
