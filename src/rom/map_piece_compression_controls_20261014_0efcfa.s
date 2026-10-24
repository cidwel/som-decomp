.setcpu "65816"
.segment "CODE"
.org $FCFA
map_control_0efcfa:
    .byte $E3 ; previous-row copy count
