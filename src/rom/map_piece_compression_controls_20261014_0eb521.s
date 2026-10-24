.setcpu "65816"
.segment "CODE"
.org $B521
map_control_0eb521:
    .byte $E0 ; previous-row copy escape
    .byte $8C ; row-distance/count
