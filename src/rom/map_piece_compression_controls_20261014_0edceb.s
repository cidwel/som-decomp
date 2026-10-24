.setcpu "65816"
.segment "CODE"
.org $DCEB
map_control_0edceb:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
