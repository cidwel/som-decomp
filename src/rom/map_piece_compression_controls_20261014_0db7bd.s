.setcpu "65816"
.segment "CODE"
.org $B7BD
map_control_0db7bd:
    .byte $E1 ; previous-row copy count
