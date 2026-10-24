.setcpu "65816"
.segment "CODE"
.org $7030
map_control_0d7030:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
