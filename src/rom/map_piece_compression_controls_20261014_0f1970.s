.setcpu "65816"
.segment "CODE"
.org $1970
map_control_0f1970:
    .byte $E1 ; previous-row copy count
