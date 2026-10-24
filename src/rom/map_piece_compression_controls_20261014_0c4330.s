.setcpu "65816"
.segment "CODE"
.org $4330
map_control_0c4330:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E1 ; previous-row copy count
