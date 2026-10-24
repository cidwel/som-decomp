.setcpu "65816"
.segment "CODE"
.org $455F
map_control_0c455f:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
