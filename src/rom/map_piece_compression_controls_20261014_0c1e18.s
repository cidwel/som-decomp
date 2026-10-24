.setcpu "65816"
.segment "CODE"
.org $1E18
map_control_0c1e18:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
