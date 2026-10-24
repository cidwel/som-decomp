.setcpu "65816"
.segment "CODE"
.org $F89B
map_control_0ff89b:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
