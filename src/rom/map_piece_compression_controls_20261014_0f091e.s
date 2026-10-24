.setcpu "65816"
.segment "CODE"
.org $091E
map_control_0f091e:
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
