.setcpu "65816"
.segment "CODE"
.org $D2CA
map_control_0dd2ca:
    .byte $E1 ; previous-row copy count
