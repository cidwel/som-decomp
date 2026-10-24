.setcpu "65816"
.segment "CODE"
.org $B65B
map_control_0fb65b:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
