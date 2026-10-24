.setcpu "65816"
.segment "CODE"
.org $7158
map_control_0c7158:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
