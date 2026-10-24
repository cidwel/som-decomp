.setcpu "65816"
.segment "CODE"
.org $0420
map_control_0f0420:
    .byte $E1 ; previous-row copy count
