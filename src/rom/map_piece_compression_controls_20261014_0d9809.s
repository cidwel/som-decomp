.setcpu "65816"
.segment "CODE"
.org $9809
map_control_0d9809:
    .byte $F1 ; progressive-copy count
    .byte $E3 ; previous-row copy count
