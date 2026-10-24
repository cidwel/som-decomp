.setcpu "65816"
.segment "CODE"
.org $D810
map_control_0dd810:
    .byte $E3 ; previous-row copy count
