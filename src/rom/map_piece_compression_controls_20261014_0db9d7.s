.setcpu "65816"
.segment "CODE"
.org $B9D7
map_control_0db9d7:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
