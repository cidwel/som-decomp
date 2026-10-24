.setcpu "65816"
.segment "CODE"
.org $25C0
map_control_0f25c0:
    .byte $E1 ; previous-row copy count
