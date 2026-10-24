.setcpu "65816"
.segment "CODE"
.org $6994
map_control_0d6994:
    .byte $F2 ; progressive-copy count
    .byte $E4 ; previous-row copy count
