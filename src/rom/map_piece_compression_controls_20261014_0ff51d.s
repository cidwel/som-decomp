.setcpu "65816"
.segment "CODE"
.org $F51D
map_control_0ff51d:
    .byte $E2 ; previous-row copy count
