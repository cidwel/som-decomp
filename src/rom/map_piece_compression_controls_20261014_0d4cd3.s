.setcpu "65816"
.segment "CODE"
.org $4CD3
map_control_0d4cd3:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
