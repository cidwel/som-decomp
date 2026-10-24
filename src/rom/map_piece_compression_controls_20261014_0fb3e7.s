.setcpu "65816"
.segment "CODE"
.org $B3E7
map_control_0fb3e7:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
