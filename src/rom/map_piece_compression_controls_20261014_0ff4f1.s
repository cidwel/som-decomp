.setcpu "65816"
.segment "CODE"
.org $F4F1
map_control_0ff4f1:
    .byte $E1 ; previous-row copy count
