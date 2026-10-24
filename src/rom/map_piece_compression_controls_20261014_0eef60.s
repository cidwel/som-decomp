.setcpu "65816"
.segment "CODE"
.org $EF60
map_control_0eef60:
    .byte $E4 ; previous-row copy count
