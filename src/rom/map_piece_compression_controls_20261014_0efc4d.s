.setcpu "65816"
.segment "CODE"
.org $FC4D
map_control_0efc4d:
    .byte $F1 ; progressive-copy count
    .byte $E1 ; previous-row copy count
