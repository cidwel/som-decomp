.setcpu "65816"
.segment "CODE"
.org $D6FC
map_control_0dd6fc:
    .byte $E0 ; previous-row copy escape
    .byte $24 ; row-distance/count
