.setcpu "65816"
.segment "CODE"
.org $F80E
map_control_0df80e:
    .byte $E1 ; previous-row copy count
