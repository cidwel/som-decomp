.setcpu "65816"
.segment "CODE"
.org $7324
map_control_0d7324:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
