.setcpu "65816"
.segment "CODE"
.org $8B8A
map_control_0c8b8a:
    .byte $F1 ; progressive-copy count
    .byte $E7 ; previous-row copy count
