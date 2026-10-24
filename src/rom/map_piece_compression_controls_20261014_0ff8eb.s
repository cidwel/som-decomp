.setcpu "65816"
.segment "CODE"
.org $F8EB
map_control_0ff8eb:
    .byte $E6 ; previous-row copy count
