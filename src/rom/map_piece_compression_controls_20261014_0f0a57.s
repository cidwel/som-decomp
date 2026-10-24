.setcpu "65816"
.segment "CODE"
.org $0A57
map_control_0f0a57:
    .byte $E8 ; backreference distance high bits
    .byte $93 ; distance low bit/count
