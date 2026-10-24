.setcpu "65816"
.segment "CODE"
.org $4CD2
map_control_0e4cd2:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
