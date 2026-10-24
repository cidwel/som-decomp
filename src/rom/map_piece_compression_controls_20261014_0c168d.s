.setcpu "65816"
.segment "CODE"
.org $168D
map_control_0c168d:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
