.setcpu "65816"
.segment "CODE"
.org $57DD
map_control_0e57dd:
    .byte $F2 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
