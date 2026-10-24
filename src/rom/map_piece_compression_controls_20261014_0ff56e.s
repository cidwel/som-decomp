.setcpu "65816"
.segment "CODE"
.org $F56E
map_control_0ff56e:
    .byte $E1 ; previous-row copy count
