.setcpu "65816"
.segment "CODE"
.org $AA8F
map_control_0eaa8f:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
