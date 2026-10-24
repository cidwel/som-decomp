.setcpu "65816"
.segment "CODE"
.org $8851
map_control_0f8851:
    .byte $E1 ; previous-row copy count
