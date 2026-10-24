.setcpu "65816"
.segment "CODE"
.org $7388
map_control_0f7388:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
