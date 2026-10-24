.setcpu "65816"
.segment "CODE"
.org $39EA
map_control_0c39ea:
    .byte $F1 ; progressive-copy count
    .byte $E6 ; previous-row copy count
