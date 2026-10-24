.setcpu "65816"
.segment "CODE"
.org $960A
map_control_0e960a:
    .byte $F1 ; progressive-copy count
    .byte $E4 ; previous-row copy count
