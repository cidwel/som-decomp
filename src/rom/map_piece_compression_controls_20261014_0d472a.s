.setcpu "65816"
.segment "CODE"
.org $472A
map_control_0d472a:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E5 ; previous-row copy count
