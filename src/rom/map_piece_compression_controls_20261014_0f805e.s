.setcpu "65816"
.segment "CODE"
.org $805E
map_control_0f805e:
    .byte $E5 ; previous-row copy count
