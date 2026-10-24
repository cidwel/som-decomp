.setcpu "65816"
.segment "CODE"
.org $F23B
map_control_0cf23b:
    .byte $F2 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
