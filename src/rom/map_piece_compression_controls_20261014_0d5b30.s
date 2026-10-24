.setcpu "65816"
.segment "CODE"
.org $5B30
map_control_0d5b30:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
