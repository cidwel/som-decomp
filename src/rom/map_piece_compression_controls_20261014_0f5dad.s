.setcpu "65816"
.segment "CODE"
.org $5DAD
map_control_0f5dad:
    .byte $E1 ; previous-row copy count
