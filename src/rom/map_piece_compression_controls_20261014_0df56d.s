.setcpu "65816"
.segment "CODE"
.org $F56D
map_control_0df56d:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
