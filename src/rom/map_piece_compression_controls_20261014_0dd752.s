.setcpu "65816"
.segment "CODE"
.org $D752
map_control_0dd752:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
