.setcpu "65816"
.segment "CODE"
.org $800C
map_control_0c800c:
    .byte $E2 ; previous-row copy count
