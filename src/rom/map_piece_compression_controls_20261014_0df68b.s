.setcpu "65816"
.segment "CODE"
.org $F68B
map_control_0df68b:
    .byte $F1 ; progressive-copy count
    .byte $E3 ; previous-row copy count
