.setcpu "65816"
.segment "CODE"
.org $F896
map_control_0ff896:
    .byte $E5 ; previous-row copy count
