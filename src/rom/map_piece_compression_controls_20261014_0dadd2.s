.setcpu "65816"
.segment "CODE"
.org $ADD2
map_control_0dadd2:
    .byte $E1 ; previous-row copy count
