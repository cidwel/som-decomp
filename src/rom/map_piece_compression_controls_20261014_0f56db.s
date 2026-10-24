.setcpu "65816"
.segment "CODE"
.org $56DB
map_control_0f56db:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
