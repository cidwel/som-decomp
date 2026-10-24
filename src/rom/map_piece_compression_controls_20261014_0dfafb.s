.setcpu "65816"
.segment "CODE"
.org $FAFB
map_control_0dfafb:
    .byte $E7 ; previous-row copy count
