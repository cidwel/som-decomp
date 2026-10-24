.setcpu "65816"
.segment "CODE"
.org $F766
map_control_0ff766:
    .byte $E1 ; previous-row copy count
