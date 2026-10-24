.setcpu "65816"
.segment "CODE"
.org $17AC
map_control_0d17ac:
    .byte $E1 ; previous-row copy count
