.setcpu "65816"
.segment "CODE"
.org $F601
map_control_0df601:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
