.setcpu "65816"
.segment "CODE"
.org $F1EA
map_control_0df1ea:
    .byte $E5 ; previous-row copy count
