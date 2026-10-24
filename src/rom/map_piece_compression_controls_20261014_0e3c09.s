.setcpu "65816"
.segment "CODE"
.org $3C09
map_control_0e3c09:
    .byte $F2 ; progressive-copy count
    .byte $E1 ; previous-row copy count
