.setcpu "65816"
.segment "CODE"
.org $4141
map_control_0f4141:
    .byte $E1 ; previous-row copy count
    .byte $F2 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
