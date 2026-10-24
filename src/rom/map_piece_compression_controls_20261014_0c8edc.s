.setcpu "65816"
.segment "CODE"
.org $8EDC
map_control_0c8edc:
    .byte $F1 ; progressive-copy count
    .byte $E1 ; previous-row copy count
