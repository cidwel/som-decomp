.setcpu "65816"
.segment "CODE"
.org $157B
map_control_0c157b:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
