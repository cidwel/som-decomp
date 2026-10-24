.setcpu "65816"
.segment "CODE"
.org $7CCF
map_control_0f7ccf:
    .byte $E7 ; previous-row copy count
