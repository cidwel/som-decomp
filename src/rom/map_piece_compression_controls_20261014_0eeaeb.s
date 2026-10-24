.setcpu "65816"
.segment "CODE"
.org $EAEB
map_control_0eeaeb:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
