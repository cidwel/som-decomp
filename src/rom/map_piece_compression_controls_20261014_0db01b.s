.setcpu "65816"
.segment "CODE"
.org $B01B
map_control_0db01b:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E1 ; previous-row copy count
