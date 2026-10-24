.setcpu "65816"
.segment "CODE"
.org $8796
map_control_0d8796:
    .byte $EE ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $0D ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $6F ; distance low bit/count
