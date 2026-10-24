.setcpu "65816"
.segment "CODE"
.org $8AFC
map_control_0f8afc:
    .byte $E4 ; previous-row copy count
