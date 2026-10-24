.setcpu "65816"
.segment "CODE"
.org $4601
map_control_0f4601:
    .byte $F2 ; progressive-copy count
    .byte $E6 ; previous-row copy count
