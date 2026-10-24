.setcpu "65816"
.segment "CODE"
.org $3FEF
map_control_0f3fef:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $35 ; row-distance/count
