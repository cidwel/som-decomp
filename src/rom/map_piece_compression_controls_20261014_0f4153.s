.setcpu "65816"
.segment "CODE"
.org $4153
map_control_0f4153:
    .byte $F1 ; progressive-copy count
    .byte $E7 ; previous-row copy count
