.setcpu "65816"
.segment "CODE"
.org $F09E
map_control_0ff09e:
    .byte $E3 ; previous-row copy count
