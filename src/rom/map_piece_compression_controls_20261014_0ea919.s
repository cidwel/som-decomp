.setcpu "65816"
.segment "CODE"
.org $A919
map_control_0ea919:
    .byte $E8 ; backreference distance high bits
    .byte $1C ; distance low bit/count
