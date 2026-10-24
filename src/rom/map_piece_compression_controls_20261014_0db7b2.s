.setcpu "65816"
.segment "CODE"
.org $B7B2
map_control_0db7b2:
    .byte $E0 ; previous-row copy escape
    .byte $8D ; row-distance/count
