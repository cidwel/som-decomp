.setcpu "65816"
.segment "CODE"
.org $CB75
map_control_0ecb75:
    .byte $E1 ; previous-row copy count
