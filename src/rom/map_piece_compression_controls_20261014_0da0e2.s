.setcpu "65816"
.segment "CODE"
.org $A0E2
map_control_0da0e2:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
