.setcpu "65816"
.segment "CODE"
.org $C1BF
map_control_0dc1bf:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
