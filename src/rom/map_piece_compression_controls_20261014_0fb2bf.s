.setcpu "65816"
.segment "CODE"
.org $B2BF
map_control_0fb2bf:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
