.setcpu "65816"
.segment "CODE"
.org $EBA8
map_control_0deba8:
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $69 ; distance low bit/count
