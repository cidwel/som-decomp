.setcpu "65816"
.segment "CODE"
.org $B8CC
map_control_0fb8cc:
    .byte $E1 ; previous-row copy count
