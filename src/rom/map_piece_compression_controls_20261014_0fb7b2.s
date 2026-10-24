.setcpu "65816"
.segment "CODE"
.org $B7B2
map_control_0fb7b2:
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
