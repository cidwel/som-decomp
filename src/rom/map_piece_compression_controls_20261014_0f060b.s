.setcpu "65816"
.segment "CODE"
.org $060B
map_control_0f060b:
    .byte $E1 ; previous-row copy count
