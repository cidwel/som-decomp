.setcpu "65816"
.segment "CODE"
.org $AF9B
map_control_0eaf9b:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
