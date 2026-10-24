.setcpu "65816"
.segment "CODE"
.org $76D5
map_control_0d76d5:
    .byte $F2 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
