.setcpu "65816"
.segment "CODE"
.org $71CC
map_control_0e71cc:
    .byte $E4 ; previous-row copy count
