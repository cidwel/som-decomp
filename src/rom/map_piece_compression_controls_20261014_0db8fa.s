.setcpu "65816"
.segment "CODE"
.org $B8FA
map_control_0db8fa:
    .byte $E4 ; previous-row copy count
