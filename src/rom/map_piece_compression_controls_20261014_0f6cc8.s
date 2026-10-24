.setcpu "65816"
.segment "CODE"
.org $6CC8
map_control_0f6cc8:
    .byte $F5 ; progressive-copy count
    .byte $EB ; backreference distance high bits
    .byte $28 ; distance low bit/count
