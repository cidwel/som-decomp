.setcpu "65816"
.segment "CODE"
.org $29C8
map_control_0f29c8:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
