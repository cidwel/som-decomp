.setcpu "65816"
.segment "CODE"
.org $050D
map_control_0f050d:
    .byte $E1 ; previous-row copy count
