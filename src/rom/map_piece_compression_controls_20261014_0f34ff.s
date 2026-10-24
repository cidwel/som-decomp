.setcpu "65816"
.segment "CODE"
.org $34FF
map_control_0f34ff:
    .byte $F2 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
