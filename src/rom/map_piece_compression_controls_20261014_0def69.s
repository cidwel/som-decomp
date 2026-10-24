.setcpu "65816"
.segment "CODE"
.org $EF69
map_control_0def69:
    .byte $F1 ; progressive-copy count
    .byte $E1 ; previous-row copy count
