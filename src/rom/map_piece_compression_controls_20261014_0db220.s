.setcpu "65816"
.segment "CODE"
.org $B220
map_control_0db220:
    .byte $E1 ; previous-row copy count
