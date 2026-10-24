.setcpu "65816"
.segment "CODE"
.org $455F
map_control_0e455f:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
