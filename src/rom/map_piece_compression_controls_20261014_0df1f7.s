.setcpu "65816"
.segment "CODE"
.org $F1F7
map_control_0df1f7:
    .byte $F1 ; progressive-copy count
    .byte $E7 ; previous-row copy count
