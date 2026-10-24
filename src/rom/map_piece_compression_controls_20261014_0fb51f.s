.setcpu "65816"
.segment "CODE"
.org $B51F
map_control_0fb51f:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
