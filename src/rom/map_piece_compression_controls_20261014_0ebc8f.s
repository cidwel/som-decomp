.setcpu "65816"
.segment "CODE"
.org $BC8F
map_control_0ebc8f:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
