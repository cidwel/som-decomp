.setcpu "65816"
.segment "CODE"
.org $B3B9
map_control_0fb3b9:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
