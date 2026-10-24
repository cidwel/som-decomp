.setcpu "65816"
.segment "CODE"
.org $8DFC
map_control_0c8dfc:
    .byte $F1 ; progressive-copy count
    .byte $E5 ; previous-row copy count
