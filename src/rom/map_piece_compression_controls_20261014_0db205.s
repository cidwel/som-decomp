.setcpu "65816"
.segment "CODE"
.org $B205
map_control_0db205:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E7 ; previous-row copy count
