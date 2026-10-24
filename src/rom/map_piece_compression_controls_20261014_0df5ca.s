.setcpu "65816"
.segment "CODE"
.org $F5CA
map_control_0df5ca:
    .byte $ED ; backreference distance high bits
    .byte $88 ; distance low bit/count
