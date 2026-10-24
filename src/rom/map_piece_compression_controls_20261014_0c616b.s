.setcpu "65816"
.segment "CODE"
.org $616B
map_control_0c616b:
    .byte $E1 ; previous-row copy count
    .byte $F3 ; progressive-copy count
