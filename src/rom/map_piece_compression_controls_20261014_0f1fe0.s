.setcpu "65816"
.segment "CODE"
.org $1FE0
map_control_0f1fe0:
    .byte $E1 ; previous-row copy count
