.setcpu "65816"
.segment "CODE"
.org $292C
map_control_0e292c:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
