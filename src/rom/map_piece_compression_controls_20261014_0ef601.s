.setcpu "65816"
.segment "CODE"
.org $F601
map_control_0ef601:
    .byte $E9 ; backreference distance high bits
    .byte $04 ; distance low bit/count
