.setcpu "65816"
.segment "CODE"
.org $2CA3
map_control_0f2ca3:
    .byte $F2 ; progressive-copy count
    .byte $E4 ; previous-row copy count
