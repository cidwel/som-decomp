.setcpu "65816"
.segment "CODE"
.org $B125
map_control_0db125:
    .byte $E0 ; previous-row copy escape
    .byte $88 ; row-distance/count
