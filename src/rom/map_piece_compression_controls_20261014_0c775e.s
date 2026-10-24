.setcpu "65816"
.segment "CODE"
.org $775E
map_control_0c775e:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
