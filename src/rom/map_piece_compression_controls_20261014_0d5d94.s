.setcpu "65816"
.segment "CODE"
.org $5D94
map_control_0d5d94:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
