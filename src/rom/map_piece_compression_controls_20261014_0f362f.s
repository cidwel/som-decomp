.setcpu "65816"
.segment "CODE"
.org $362F
map_control_0f362f:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
