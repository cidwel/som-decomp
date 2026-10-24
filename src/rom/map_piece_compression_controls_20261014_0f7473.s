.setcpu "65816"
.segment "CODE"
.org $7473
map_control_0f7473:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
