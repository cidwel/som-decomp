.setcpu "65816"
.segment "CODE"
.org $8F6C
map_control_0e8f6c:
    .byte $E0 ; previous-row copy escape
    .byte $94 ; row-distance/count
