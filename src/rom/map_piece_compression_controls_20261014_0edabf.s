.setcpu "65816"
.segment "CODE"
.org $DABF
map_control_0edabf:
    .byte $E6 ; previous-row copy count
