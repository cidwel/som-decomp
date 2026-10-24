.setcpu "65816"
.segment "CODE"
.org $7C1B
map_control_0d7c1b:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
