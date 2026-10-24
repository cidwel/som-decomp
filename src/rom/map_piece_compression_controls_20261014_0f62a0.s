.setcpu "65816"
.segment "CODE"
.org $62A0
map_control_0f62a0:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
