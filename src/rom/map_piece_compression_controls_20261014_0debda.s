.setcpu "65816"
.segment "CODE"
.org $EBDA
map_control_0debda:
    .byte $E1 ; previous-row copy count
