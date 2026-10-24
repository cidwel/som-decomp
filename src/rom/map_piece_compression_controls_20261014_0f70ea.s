.setcpu "65816"
.segment "CODE"
.org $70EA
map_control_0f70ea:
    .byte $E3 ; previous-row copy count
