.setcpu "65816"
.segment "CODE"
.org $47FD
map_control_0c47fd:
    .byte $ED ; backreference distance high bits
    .byte $04 ; distance low bit/count
