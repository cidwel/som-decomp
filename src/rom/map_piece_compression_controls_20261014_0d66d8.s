.setcpu "65816"
.segment "CODE"
.org $66D8
map_control_0d66d8:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
