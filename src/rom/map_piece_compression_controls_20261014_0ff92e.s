.setcpu "65816"
.segment "CODE"
.org $F92E
map_control_0ff92e:
    .byte $E1 ; previous-row copy count
