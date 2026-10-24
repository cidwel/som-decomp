.setcpu "65816"
.segment "CODE"
.org $6D18
map_control_0c6d18:
    .byte $F3 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
