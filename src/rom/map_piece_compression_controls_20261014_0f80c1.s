.setcpu "65816"
.segment "CODE"
.org $80C1
map_control_0f80c1:
    .byte $E5 ; previous-row copy count
