.setcpu "65816"
.segment "CODE"
.org $4F51
map_control_0f4f51:
    .byte $E1 ; previous-row copy count
