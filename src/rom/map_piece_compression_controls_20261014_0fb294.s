.setcpu "65816"
.segment "CODE"
.org $B294
map_control_0fb294:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
