.setcpu "65816"
.segment "CODE"
.org $BA50
map_control_0fba50:
    .byte $F2 ; progressive-copy count
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
