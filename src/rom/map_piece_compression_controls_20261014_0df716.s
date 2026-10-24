.setcpu "65816"
.segment "CODE"
.org $F716
map_control_0df716:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
