.setcpu "65816"
.segment "CODE"
.org $B08D
map_control_0db08d:
    .byte $E6 ; previous-row copy count
