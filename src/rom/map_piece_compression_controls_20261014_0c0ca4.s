.setcpu "65816"
.segment "CODE"
.org $0CA4
map_control_0c0ca4:
    .byte $F2 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
