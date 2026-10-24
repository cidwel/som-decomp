.setcpu "65816"
.segment "CODE"
.org $ADDF
map_control_0daddf:
    .byte $E3 ; previous-row copy count
