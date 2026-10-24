.setcpu "65816"
.segment "CODE"
.org $423B
map_control_0e423b:
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $88 ; distance low bit/count
