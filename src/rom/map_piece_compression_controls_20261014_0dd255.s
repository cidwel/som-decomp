.setcpu "65816"
.segment "CODE"
.org $D255
map_control_0dd255:
    .byte $E1 ; previous-row copy count
