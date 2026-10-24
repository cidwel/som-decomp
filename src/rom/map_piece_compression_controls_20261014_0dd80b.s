.setcpu "65816"
.segment "CODE"
.org $D80B
map_control_0dd80b:
    .byte $E2 ; previous-row copy count
