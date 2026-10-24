.setcpu "65816"
.segment "CODE"
.org $B303
map_control_0db303:
    .byte $E1 ; previous-row copy count
