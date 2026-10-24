.setcpu "65816"
.segment "CODE"
.org $F360
map_control_0df360:
    .byte $E1 ; previous-row copy count
