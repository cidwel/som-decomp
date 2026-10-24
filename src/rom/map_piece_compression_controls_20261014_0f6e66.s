.setcpu "65816"
.segment "CODE"
.org $6E66
map_control_0f6e66:
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E1 ; previous-row copy count
