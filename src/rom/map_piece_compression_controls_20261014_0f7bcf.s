.setcpu "65816"
.segment "CODE"
.org $7BCF
map_control_0f7bcf:
    .byte $E5 ; previous-row copy count
