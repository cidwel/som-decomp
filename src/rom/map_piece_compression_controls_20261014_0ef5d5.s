.setcpu "65816"
.segment "CODE"
.org $F5D5
map_control_0ef5d5:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
