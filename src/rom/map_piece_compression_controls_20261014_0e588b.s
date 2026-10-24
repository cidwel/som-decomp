.setcpu "65816"
.segment "CODE"
.org $588B
map_control_0e588b:
    .byte $F2 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
