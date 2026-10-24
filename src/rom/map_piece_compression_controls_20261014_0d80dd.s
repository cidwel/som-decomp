.setcpu "65816"
.segment "CODE"
.org $80DD
map_control_0d80dd:
    .byte $E7 ; previous-row copy count
