.setcpu "65816"
.segment "CODE"
.org $20E8
map_control_0f20e8:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
