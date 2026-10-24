.setcpu "65816"
.segment "CODE"
.org $A6B2
map_control_0fa6b2:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
