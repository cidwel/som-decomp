.setcpu "65816"
.segment "CODE"
.org $12FA
map_control_0f12fa:
    .byte $E1 ; previous-row copy count
