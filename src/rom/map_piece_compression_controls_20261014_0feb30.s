.setcpu "65816"
.segment "CODE"
.org $EB30
map_control_0feb30:
    .byte $F1 ; progressive-copy count
    .byte $EF ; backreference distance high bits
    .byte $0B ; distance low bit/count
