.setcpu "65816"
.segment "CODE"
.org $80DA
map_control_0e80da:
    .byte $E1 ; previous-row copy count
