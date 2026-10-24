.setcpu "65816"
.segment "CODE"
.org $5BD6
map_control_0f5bd6:
    .byte $C9 ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E5 ; previous-row copy count
    .byte $EE ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $EA ; backreference distance high bits
    .byte $8A ; distance low bit/count
