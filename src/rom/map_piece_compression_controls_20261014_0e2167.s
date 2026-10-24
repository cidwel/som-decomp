.setcpu "65816"
.segment "CODE"
.org $2167
map_control_0e2167:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
