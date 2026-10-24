.setcpu "65816"
.segment "CODE"
.org $138F
map_control_0f138f:
    .byte $E0 ; previous-row copy escape
    .byte $24 ; row-distance/count
