.setcpu "65816"
.segment "CODE"
.org $FF8E
map_control_0dff8e:
    .byte $E5 ; previous-row copy count
