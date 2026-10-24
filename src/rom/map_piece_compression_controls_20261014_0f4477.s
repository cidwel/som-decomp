.setcpu "65816"
.segment "CODE"
.org $4477
map_control_0f4477:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
