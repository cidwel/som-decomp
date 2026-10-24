.setcpu "65816"
.segment "CODE"
.org $4D15
map_control_0f4d15:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
