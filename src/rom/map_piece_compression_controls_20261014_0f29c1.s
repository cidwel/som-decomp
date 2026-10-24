.setcpu "65816"
.segment "CODE"
.org $29C1
map_control_0f29c1:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
