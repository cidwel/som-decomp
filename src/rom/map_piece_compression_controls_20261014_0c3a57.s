.setcpu "65816"
.segment "CODE"
.org $3A57
map_control_0c3a57:
    .byte $ED ; backreference distance high bits
    .byte $88 ; distance low bit/count
