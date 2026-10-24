.setcpu "65816"
.segment "CODE"
.org $4CF5
map_control_0f4cf5:
    .byte $F1 ; progressive-copy count
    .byte $E1 ; previous-row copy count
