.setcpu "65816"
.segment "CODE"
.org $96CF
map_control_0d96cf:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E2 ; previous-row copy count
