.setcpu "65816"
.segment "CODE"
.org $A4AF
map_control_0da4af:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $F1 ; progressive-copy count
