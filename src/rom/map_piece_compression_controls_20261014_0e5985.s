.setcpu "65816"
.segment "CODE"
.org $5985
map_control_0e5985:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $93 ; row-distance/count
