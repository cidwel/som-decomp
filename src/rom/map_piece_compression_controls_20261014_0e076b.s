.setcpu "65816"
.segment "CODE"
.org $076B
map_control_0e076b:
    .byte $F2 ; progressive-copy count
    .byte $E1 ; previous-row copy count
