.setcpu "65816"
.segment "CODE"
.org $4CC4
map_control_0e4cc4:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
