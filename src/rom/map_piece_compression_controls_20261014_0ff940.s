.setcpu "65816"
.segment "CODE"
.org $F940
map_control_0ff940:
    .byte $E6 ; previous-row copy count
