.setcpu "65816"
.segment "CODE"
.org $5CAF
map_control_0f5caf:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
