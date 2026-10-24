.setcpu "65816"
.segment "CODE"
.org $E400
map_control_0de400:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
