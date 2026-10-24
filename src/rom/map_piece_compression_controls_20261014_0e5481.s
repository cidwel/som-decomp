.setcpu "65816"
.segment "CODE"
.org $5481
map_control_0e5481:
    .byte $F3 ; progressive-copy count
    .byte $E4 ; previous-row copy count
