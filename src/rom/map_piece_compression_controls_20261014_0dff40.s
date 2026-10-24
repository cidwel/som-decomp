.setcpu "65816"
.segment "CODE"
.org $FF40
map_control_0dff40:
    .byte $E2 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $06 ; distance low bit/count
