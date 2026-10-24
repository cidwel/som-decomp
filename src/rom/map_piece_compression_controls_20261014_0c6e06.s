.setcpu "65816"
.segment "CODE"
.org $6E06
map_control_0c6e06:
    .byte $E1 ; previous-row copy count
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
