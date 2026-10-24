.setcpu "65816"
.segment "CODE"
.org $E66B
map_control_0de66b:
    .byte $E0 ; previous-row copy escape
    .byte $8C ; row-distance/count
