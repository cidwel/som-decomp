.setcpu "65816"
.segment "CODE"
.org $EAAA
map_control_0eeaaa:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
