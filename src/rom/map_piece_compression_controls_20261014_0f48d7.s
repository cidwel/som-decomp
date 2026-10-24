.setcpu "65816"
.segment "CODE"
.org $48D7
map_control_0f48d7:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
