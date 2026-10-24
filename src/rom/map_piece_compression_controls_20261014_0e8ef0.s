.setcpu "65816"
.segment "CODE"
.org $8EF0
map_control_0e8ef0:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
