.setcpu "65816"
.segment "CODE"
.org $80DC
map_control_0e80dc:
    .byte $E5 ; previous-row copy count
