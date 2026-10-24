.setcpu "65816"
.segment "CODE"
.org $B080
map_control_0db080:
    .byte $E1 ; previous-row copy count
