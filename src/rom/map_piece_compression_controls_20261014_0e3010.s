.setcpu "65816"
.segment "CODE"
.org $3010
map_control_0e3010:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
