.setcpu "65816"
.segment "CODE"
.org $5879
map_control_0d5879:
    .byte $E0 ; previous-row copy escape
    .byte $8D ; row-distance/count
