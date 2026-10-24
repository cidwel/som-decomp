.setcpu "65816"
.segment "CODE"
.org $EE80
map_control_0eee80:
    .byte $E1 ; previous-row copy count
