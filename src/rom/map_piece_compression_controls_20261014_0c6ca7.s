.setcpu "65816"
.segment "CODE"
.org $6CA7
map_control_0c6ca7:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
