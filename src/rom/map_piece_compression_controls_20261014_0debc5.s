.setcpu "65816"
.segment "CODE"
.org $EBC5
map_control_0debc5:
    .byte $E0 ; previous-row copy escape
    .byte $94 ; row-distance/count
