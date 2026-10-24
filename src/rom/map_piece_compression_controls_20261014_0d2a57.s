.setcpu "65816"
.segment "CODE"
.org $2A57
map_control_0d2a57:
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
