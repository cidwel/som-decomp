.setcpu "65816"
.segment "CODE"
.org $F971
map_control_0ff971:
    .byte $E2 ; previous-row copy count
