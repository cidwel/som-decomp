.setcpu "65816"
.segment "CODE"
.org $D7FC
map_control_0dd7fc:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
