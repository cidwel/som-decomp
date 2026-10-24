.setcpu "65816"
.segment "CODE"
.org $0C0F
map_control_0c0c0f:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
