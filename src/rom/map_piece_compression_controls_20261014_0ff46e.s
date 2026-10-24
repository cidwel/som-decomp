.setcpu "65816"
.segment "CODE"
.org $F46E
map_control_0ff46e:
    .byte $E1 ; previous-row copy count
