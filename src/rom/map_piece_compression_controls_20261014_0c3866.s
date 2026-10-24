.setcpu "65816"
.segment "CODE"
.org $3866
map_control_0c3866:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
