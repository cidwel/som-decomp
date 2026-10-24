.setcpu "65816"
.segment "CODE"
.org $08C8
map_control_0f08c8:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
