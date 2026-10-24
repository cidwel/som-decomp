.setcpu "65816"
.segment "CODE"
.org $3BEC
map_control_0f3bec:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E5 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
