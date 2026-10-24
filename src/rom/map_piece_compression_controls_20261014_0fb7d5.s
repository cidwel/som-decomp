.setcpu "65816"
.segment "CODE"
.org $B7D5
map_control_0fb7d5:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
