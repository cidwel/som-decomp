.setcpu "65816"
.segment "CODE"
.org $FFE0
map_control_0dffe0:
    .byte $F1 ; progressive-copy count
    .byte $E3 ; previous-row copy count
