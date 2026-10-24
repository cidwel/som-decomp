.setcpu "65816"
.segment "CODE"
.org $D704
map_control_0dd704:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
