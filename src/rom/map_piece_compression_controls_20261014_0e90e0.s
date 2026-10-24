.setcpu "65816"
.segment "CODE"
.org $90E0
map_control_0e90e0:
    .byte $EB ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $32 ; distance low bit/count
