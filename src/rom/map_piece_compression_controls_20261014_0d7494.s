.setcpu "65816"
.segment "CODE"
.org $7494
map_control_0d7494:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
