.setcpu "65816"
.segment "CODE"
.org $FDBF
map_control_0dfdbf:
    .byte $E5 ; previous-row copy count
