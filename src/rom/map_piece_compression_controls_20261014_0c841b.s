.setcpu "65816"
.segment "CODE"
.org $841B
map_control_0c841b:
    .byte $F1 ; progressive-copy count
    .byte $E6 ; previous-row copy count
