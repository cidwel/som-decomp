.setcpu "65816"
.segment "CODE"
.org $3022
map_control_0d3022:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $F3 ; progressive-copy count
