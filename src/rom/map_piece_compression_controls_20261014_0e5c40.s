.setcpu "65816"
.segment "CODE"
.org $5C40
map_control_0e5c40:
    .byte $F2 ; progressive-copy count
    .byte $E9 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E3 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $EA ; backreference distance high bits
    .byte $84 ; distance low bit/count
