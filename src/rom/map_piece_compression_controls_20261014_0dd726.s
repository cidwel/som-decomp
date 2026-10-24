.setcpu "65816"
.segment "CODE"
.org $D726
map_control_0dd726:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
