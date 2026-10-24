.setcpu "65816"
.segment "CODE"
.org $2866
map_control_0e2866:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
