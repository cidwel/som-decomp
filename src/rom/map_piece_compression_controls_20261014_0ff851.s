.setcpu "65816"
.segment "CODE"
.org $F851
map_control_0ff851:
    .byte $E2 ; previous-row copy count
