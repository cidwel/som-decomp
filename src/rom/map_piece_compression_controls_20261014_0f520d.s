.setcpu "65816"
.segment "CODE"
.org $520D
map_control_0f520d:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
