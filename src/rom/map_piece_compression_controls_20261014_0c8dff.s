.setcpu "65816"
.segment "CODE"
.org $8DFF
map_control_0c8dff:
    .byte $F4 ; progressive-copy count
    .byte $E5 ; previous-row copy count
