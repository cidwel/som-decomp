.setcpu "65816"
.segment "CODE"
.org $B532
map_control_0db532:
    .byte $E1 ; previous-row copy count
