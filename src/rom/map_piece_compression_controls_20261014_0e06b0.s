.setcpu "65816"
.segment "CODE"
.org $06B0
map_control_0e06b0:
    .byte $F2 ; progressive-copy count
    .byte $E1 ; previous-row copy count
