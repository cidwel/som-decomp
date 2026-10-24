.setcpu "65816"
.segment "CODE"
.org $B514
map_control_0db514:
    .byte $E2 ; previous-row copy count
