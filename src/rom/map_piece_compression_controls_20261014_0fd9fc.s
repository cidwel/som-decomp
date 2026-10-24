.setcpu "65816"
.segment "CODE"
.org $D9FC
map_control_0fd9fc:
    .byte $E6 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $89 ; distance low bit/count
