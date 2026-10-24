.setcpu "65816"
.segment "CODE"
.org $22EE
map_control_0f22ee:
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E3 ; previous-row copy count
