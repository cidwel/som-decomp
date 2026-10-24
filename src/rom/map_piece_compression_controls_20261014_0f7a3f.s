.setcpu "65816"
.segment "CODE"
.org $7A3F
map_control_0f7a3f:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
