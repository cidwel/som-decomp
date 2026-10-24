.setcpu "65816"
.segment "CODE"
.org $6E99
map_control_0f6e99:
    .byte $EB ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $87 ; distance low bit/count
