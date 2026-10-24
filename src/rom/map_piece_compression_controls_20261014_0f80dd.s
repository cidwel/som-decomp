.setcpu "65816"
.segment "CODE"
.org $80DD
map_control_0f80dd:
    .byte $E5 ; previous-row copy count
