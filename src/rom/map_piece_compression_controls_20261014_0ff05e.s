.setcpu "65816"
.segment "CODE"
.org $F05E
map_control_0ff05e:
    .byte $E4 ; previous-row copy count
