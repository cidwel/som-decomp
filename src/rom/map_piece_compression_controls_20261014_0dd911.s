.setcpu "65816"
.segment "CODE"
.org $D911
map_control_0dd911:
    .byte $E5 ; previous-row copy count
