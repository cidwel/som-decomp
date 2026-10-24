.setcpu "65816"
.segment "CODE"
.org $749E
map_control_0d749e:
    .byte $F1 ; progressive-copy count
    .byte $E3 ; previous-row copy count
