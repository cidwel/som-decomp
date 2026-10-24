.setcpu "65816"
.segment "CODE"
.org $56E3
map_control_0e56e3:
    .byte $E7 ; previous-row copy count
    .byte $F1 ; progressive-copy count
