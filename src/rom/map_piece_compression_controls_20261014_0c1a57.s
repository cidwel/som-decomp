.setcpu "65816"
.segment "CODE"
.org $1A57
map_control_0c1a57:
    .byte $EB ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
