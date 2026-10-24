.setcpu "65816"
.segment "CODE"
.org $FD24
map_control_0dfd24:
    .byte $E1 ; previous-row copy count
