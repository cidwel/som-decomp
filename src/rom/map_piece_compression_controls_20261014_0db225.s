.setcpu "65816"
.segment "CODE"
.org $B225
map_control_0db225:
    .byte $E5 ; previous-row copy count
