.setcpu "65816"
.segment "CODE"
.org $27B4
map_control_0f27b4:
    .byte $EC ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
