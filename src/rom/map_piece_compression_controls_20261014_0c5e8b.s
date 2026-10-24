.setcpu "65816"
.segment "CODE"
.org $5E8B
map_control_0c5e8b:
    .byte $F2 ; progressive-copy count
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
